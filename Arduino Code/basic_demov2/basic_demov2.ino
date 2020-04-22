#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define ENABLE 1
#define DISABLE 0
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int heading = 0;
boolean directionSet = 0;
int pos = 0;
int servo_motor_En=0;
int set_ang = 0;
#define TRIGGER_PIN 22
#define ECHO_PIN 21
#define MAX_DISTANCE 350

NewPing sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int stop_flag = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Motor test");
  Serial3.begin(9600);
  Serial.println("Raspberry comm");

  // Control the protocol
   while(!Serial3.available()){}
    while(Serial3.available()){   
        int c = Serial3.read();
        if(c == 'P'){
          Serial3.write('O');
          Serial.write(c); 
        }
   }

  myservo.attach(10);
  Serial.println("Set up shake done");
    
  motor1.setSpeed(50);
  motor2.setSpeed(50);
  motor3.setSpeed(50);
  motor4.setSpeed(50);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  compassset();
  delay(2000);
}

//==================Main=====================
void loop() {
    // put your main code here, to run repeatedly:
    int i;
    int dist = 999;
  
    // control Light
    //Heartbeat signal
    Serial3.write('O');
    

//    //Detect
//    dist = detect();
//    if((dist != 0) && dist <= 15 && (stop_flag != 1))
//    {
//      go_backward(200);
//      delay(550);
//      //go_left(2200);
//      stopcar();
//    }
//    Serial.println(dist);
//    

    if (Serial3.available()){
      int intByte = Serial3.read();
  
      // The DEBUG code
      Serial.print("Read: ");
      Serial.print(intByte);
      Serial.print(" 0x");
      Serial.println(intByte, HEX);

      command(intByte);
    }


//  myservo.detach();
}

//=============Command Recv=====================
//==============================================
void command(int cmd)
{
    switch(cmd){
      case 'w':
        go_forward(128);
        break;
      case 'W':
        go_forward(255);
        break;
      case 's':
        go_backward(128);
        break;
      case 'S':
        go_backward(255);
        break;
      case 'a':
        go_left(200);
        break;
      case 'A':
        go_left(3000);
        break;
      case 'd':
        go_right(200);
        break;
       case 'D':
        go_right(3000);
        break;
      case 'x':
        stopcar();
        break;
      case 'z':
        testcase();
        break;
      case 'u':
        //turn_down();
        checkdirection(20);
        stopcar();
        break;
      case '0':
        draw_Sun();
        stopcar();
        break;
      case '1':
        draw_Magic();
        stopcar();
        break;
      case '2':
        draw_Love();
        stopcar();
        break;
      case '3':
        draw_Moon();
        stopcar();
        break;
      case '4':
        draw_King();
        stopcar();
        break;
      case '5':
        draw_pope();
        stopcar();
        break;
      case '6':
        draw_priest();
        stopcar();
        break;
      case '7':
        draw_gear();
        stopcar();
        break;
      case '8':
        draw_Star();
        stopcar();
        break;
      case '9':
        draw_Tower();
        stopcar();
        break;
      case 'c':
        draw_circle();
        stopcar();
        break;
      case 'j':
        EnSignal(90);
        break;
      case 'k':
        UnSignal(90);
        break;
      default:
        break;
    }
}


//=================Utils Func=======================
void go_forward(int rate)
{
  stop_flag = 0;
  motor1.setSpeed(rate);
  motor2.setSpeed(rate);
  motor3.setSpeed(rate);
  motor4.setSpeed(rate);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void std_forward(int delay_time)
{
  go_forward(250);
  delay(delay_time);
  stop_flag = 0;
}

void std_backward(int delay_time)
{
  go_backward(250);
  delay(delay_time);
  stop_flag = 0;
}

void go_backward(int rate)
{
  
  stop_flag = 0;
  motor1.setSpeed(rate);
  motor2.setSpeed(rate);
  motor3.setSpeed(rate);
  motor4.setSpeed(rate);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void go_right(int rotate_time)
{
  stop_flag = 0;
  // go forward
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  //motor2.run(RELEASE);
  
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);

  delay(rotate_time);
  go_forward(180);
  return; 
}

void go_left(int rotate_time)
{
  stop_flag = 0;
  motor1.setSpeed(255);
  //motor1.run(RELEASE);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  
  motor4.setSpeed(200);
  motor4.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  
  delay(rotate_time);
  go_forward(180);
  return;
}

void turn_down()
{
  stop_flag = 0;
  go_left(2000);
  go_backward(500);
  delay(300);
  go_left(2000);
  go_backward(500);
  delay(200);
  go_left(3000);
  stopcar();
}

void stopcar()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  stop_flag = 1;
}


int detect()
{
  int dist;
  dist = sensor.ping_cm();
  Serial.print("Ping: ");
  Serial.print(dist);
  Serial.print("cm");
  return dist;
}

void stopServo(int angle)
{
  myservo.write(angle);
  delay(3000);
}

void EnSignal(int angle)
{
   for (pos = angle; pos > 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void UnSignal(int angle)
{
  for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
