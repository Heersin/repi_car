import paho.mqtt.client as mqtt
import time
import numpy as np
from keras.models import load_model
from keras.preprocessing import image
from PIL import Image
import on
import sys

USERID = "sws002"
PASSWORD = "shorthair"
resp_callback = None
TMP_FILE = "./voice.mp3"

def on_connect(client, userdata, flags, rc):
    print("connect.result code is {}".format(rc))
    client.subscribe(USERID+"/IMAGE/classify")

def on_message(client, userdata, msg):
    print("receive message. Writing to", TMP_FILE)
    img = msg.payload
    with open(TMP_FILE,"wb") as f:
        f.write(img)
    speak(TMP_FILE)
    client.publish(USERID+"/IMAGE/predict", "received")
def setup():
    global client
    global dict
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect("192.168.43.240", 1883, 30)
    client.loop_start()
def send_image(filename):
    img = load_image(filename)
    client.publish(USERID+"/IMAGE/classify", img)
def resp_handler(label):
    print("reveived!")

def load_image(image):
    img = Image.open(image)
    img = img.resize((249,249))
    imgarray = np.array(img)/255.0
    final = np.expand_dims(imgarray, axis=0)
    print("ok")
    return final
def speak(path):
    command = "omxplayer -o local " + path
    os.system(command)

if __name__ == '__main__':
    # model = load_model("./cats_v14_forTest.hd5")
    setup()
    while True:
        pass