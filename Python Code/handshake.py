import serial
import time


alive_flag = 0
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)

while(alive_flag == 0):
    ser.write("S".encode('utf-8'))
    print("[.]Waiting")
    time.sleep(1)
    response = ser.readline()
    if response is not '':
        alive_flag = 1
        break
    print(".",end='')


    time.sleep(1)
    response = ser.readline()
    if response is not '':
        alive_flag = 1
        break
    print(".",end='')

    time.sleep(1)
    response = ser.readline()
    if response is not '':
        alive_flag = 1
        break
    print(".",end='')

    print("[-]Not Alive Try again")

print("[*]Found Ardunio")
if ((response.decode('utf-8')) == 'A'):
    print("[*]ACK from Ardunio recved!")
    serial.write('ACK')
else:
    print("[-]Oops recved:" + (response.decode('utf-8')[:-1]))
    exit(0)