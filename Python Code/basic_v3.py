import serial
import time
import sys
from picamera import PiCamera, Color
from time import sleep
import io
import picamera
import logging
import socketserver
from threading import Condition
from http import server
import threading
import os
import tty
import termios


mycamera = picamera.PiCamera(resolution='640x480', framerate=30) 
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)
PAGE="""\
<html>
<head>
<title>SWS3009 PiCamera Peek-a-boo</title>
</head>
<body>
<h1>PiCamera Streaming Demo:</h1>
<img src="stream.mjpg" width="640" height="480" />
</body>
</html>
"""

class StreamingOutput(object):
    def __init__(self):
        self.frame = None
        self.buffer = io.BytesIO()
        self.condition = Condition()

    def write(self, buf):
        if buf.startswith(b'\xff\xd8'):
            # New frame, copy the existing buffer's content and notify all
            # clients it's available
            self.buffer.truncate()
            with self.condition:
                self.frame = self.buffer.getvalue()
                self.condition.notify_all()
            self.buffer.seek(0)
        return self.buffer.write(buf)

class StreamingHandler(server.BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.send_response(301)
            self.send_header('Location', '/index.html')
            self.end_headers()
        elif self.path == '/index.html':
            content = PAGE.encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'text/html')
            self.send_header('Content-Length', len(content))
            self.end_headers()
            self.wfile.write(content)
        elif self.path == '/stream.mjpg':
            self.send_response(200)
            self.send_header('Age', 0)
            self.send_header('Cache-Control', 'no-cache, private')
            self.send_header('Pragma', 'no-cache')
            self.send_header('Content-Type', 'multipart/x-mixed-replace; boundary=FRAME')
            self.end_headers()
            try:
                while True:
                    with output.condition:
                        output.condition.wait()
                        frame = output.frame
                    self.wfile.write(b'--FRAME\r\n')
                    self.send_header('Content-Type', 'image/jpeg')
                    self.send_header('Content-Length', len(frame))
                    self.end_headers()
                    self.wfile.write(frame)
                    self.wfile.write(b'\r\n')
            except Exception as e:
                logging.warning(
                    'Removed streaming client %s: %s',
                    self.client_address, str(e))
        else:
            self.send_error(404)
            self.end_headers()


class StreamingServer(socketserver.ThreadingMixIn, server.HTTPServer):
    allow_reuse_address = True
    daemon_threads = True


def take_photo():

    #######################################
    #Initialization
    #######################################
    mycamera.start_preview()
    mycamera.annotate_background = Color('white')
    mycamera.annotate_foreground = Color('red')
    mycamera.annotate_text = " SWS3009B - 2019"
    sleep(5)
    name_time = time.ctime()
    picture_name = '/home/pi/Desktop/camera/cat' + str(name_time) + '.jpg'
    mycamera.capture(picture_name)
    mycamera.stop_preview()

def handshake():
    alive_flag = 0

    while(alive_flag == 0):
        ser.write("P".encode('utf-8'))
        print("[.]Waiting")
        time.sleep(1)
        response = ser.read().decode('utf-8')
        if response is not '':
            alive_flag = 1
            break
        print(".",end='')

        time.sleep(1)
        response = ser.read().decode('utf-8')
        if response is not '':
            alive_flag = 1
            break
        print(".",end='')

        print("[-]Not Alive Try again")

    print("[*]Found Ardunio")
    if (response == 'O'):
        print("[*]ACK from Ardunio recved!")
        ser.write('O'.encode('utf-8'))
    else:
        print("[-]Oops recved:" + (response))
        exit(0)

def remoteCmd():
    try:
        while True:
            std = sys.stdin.fileno()
            settings = termios.tcgetattr(std)
            try:
                tty.setraw(std)
                ch = sys.stdin.read(1)
            finally:
                termios.tcsetattr(std,termios.TCSADRAIN, settings)
            if ch == 'w':
                print('w')
            elif ch == 's':
                print('s')
            elif ch == 'a':
                print('a')
            elif ch == 'd':
                print('d')
            elif ch == 'W':
                print('W')
            elif ch == 'S':
                print('S')
            elif ch == 'x':
                print('Stop')
            elif ch == 't':
                print('Take Pic')
                take_photo()
            elif ch == 'u':
                print('Turn')
            elif ch == 'q':
                print('Quit')
                break
            else:
                print('Nothing')
            ser.write(ch.encode('utf-8'))
            response = ser.read()
            print(response.decode('utf-8'))
    except KeyboardInterrupt:
        ser.close()

def cameraEye():
        mycamera.start_recording(output, format='mjpeg')
        try:
            address = ('', 8000)
            server = StreamingServer(address, StreamingHandler)
            server.serve_forever()
        finally:
            mycamera.stop_recording()
            mycamera.close()


output = StreamingOutput()
if __name__ == '__main__':
    t = threading.Thread(target=cameraEye)
    t.start()
    handshake()
    remoteCmd()
