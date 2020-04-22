import serial
import time
import sys
from picamera import PiCamera, Color
from time import sleep
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)

        t = threading.Thread(target=connSocket, args=(connectionSocket, addr,))
        t.start()

def handshake():
    alive_flag = 0

    while(alive_flag == 0):
        ser.write("S")
        print("[.]Waiting")
        time.sleep(1)
        response = ser.readline().decode('utf-8')
        if response is not '':
            alive_flag = 1
            break
        print(".",end='')


        time.sleep(1)
        response = ser.readline().decode('utf-8')
        if response is not '':
            alive_flag = 1
            break
        print(".",end='')


        time.sleep(1)
        response = ser.readline().decode('utf-8')
        if response is not '':
            alive_flag = 1
            break
        print(".",end='')

        print("[-]Not Alive Try again")

    print("[*]Found Ardunio")
    if (response == 'A'):
        print("[*]ACK from Ardunio recved!")
        ser.write('A')
    else:
        print("[-]Oops recved:" + (response))
        exit(0)

def take_photo():
    #######################################
    #Initialization
    #######################################
    demoCamera = PiCamera()

    demoCamera.start_preview()
    demoCamera.annotate_background = Color('white')
    demoCamera.annotate_foreground = Color('red')
    demoCamera.annotate_text = " SWS3009B - 2019"
    sleep(5)

    name_time = time.ctime()
    picture_name = '/home/pi/Desktop/camera/cat' + str(name_time) + '.jpg'
    demoCamera.capture(picture_name)
    demoCamera.stop_preview()


def remoteCmd():
    try:
        while 1:
            user = input() + '\n'
            if(user == 't\n'):
                take_photo()
                continue
            ser.write(user.encode('utf-8'))
            response = ser.readline()
            print(response.decode('utf-8'))
        except KeyboardInterrupt:
            ser.close()


if __name__ == '__main__':
    handshake()
    remoteCmd()