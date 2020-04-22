import paho.mqtt.client as mqtt
import time
from aip import AipOcr
""" 你的 APPID AK SK """
APP_ID = '16842369'
API_KEY = 'uDegtQ1avr7dARXdg91vprIX'
SECRET_KEY = 'XH2HHE4HHcUN753XbY8f0Pg0onLlSwT7'
client = AipOcr(APP_ID, API_KEY, SECRET_KEY)

USERID = "sws002"
PASSWORD = "shorthair"
resp_callback = None
PATH = ""
def on_connect(client, userdata, flags, rc):
    print("connect.result code is {}".format(rc))
    client.subscribe(USERID+"/IMAGE/predict")

def on_message(client, userdata, msg):
    print("receive message from server", msg.payload)

    tmp = msg.payload.decode("utf-8")

    if(resp_callback is not None):
        resp_callback(tmp)
def setup():
    global client

    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect("192.168.43.240", 1883, 30)
    client.loop_start()
def load_image(filename):
    with open(filename,"rb") as f:
        data = f.read()
    return data
def send_image(filename):
    img = load_image(filename)
    client.publish(USERID+"/IMAGE/classify", img)
def resp_handler(label):
    print("-------------Response-----------")
    print("keyword:",label)
def main():
    global resp_callback
    setup()
    resp_callback = resp_handler
    time.sleep(2)
    print("send")
    send_image(PATH)
    time.sleep(5)
    while True:
        pass
if __name__ == '__main__':
    main()