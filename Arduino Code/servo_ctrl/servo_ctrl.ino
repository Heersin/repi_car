#include <Servo.h>
#define ENABLE 1
#define DISABLE 0
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
int flag = 1;
void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if(flag == ENABLE){
    EnSignal(90);
    stopServo(90);
    flag = 2;
  }
  if (flag == DISABLE)
  {
    UnSignal(90);
    stopServo(0);
    flag = 2;
  }
  
//  myservo.detach();
}

void stopServo(int angle)
{
  myservo.write(angle);
  delay(3000);
}

void EnSignal(int angle)
{
  for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void UnSignal(int angle)
{
   for (pos = angle; pos > 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
