void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
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

void draw_Sun()
{
    stop_flag=0;
    go_forward(200);
    turn_right(2000);
    go_forward(300);
    turn_right(2000);
    go_forward(400);
    turn_right(2000);
    go_forward(500);
    turn_right(2000);
    go_forward(600);
    turn_right(2000);
    go_forward(700);
    turn_right(2000);
    go_forward(600);
    turn_right(2000);
    go_forward(700);
    stopcar();
    servo_motor_En=0;
    turn_left(500);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_right(1800);
    go_forward(400);
    turn_right(1800);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_left(1800);
    go_forward(300);
    turn_left(1000);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_right(1800);
    go_forward(400);
    turn_left(1800);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_right(1800);
    go_forward(400);
    turn_left(900);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_right(1800);
    go_forward(400);
    turn_left(1500);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
    turn_left(1800);
    go_forward(400);
    turn_right(1900);
    servo_motor_En=1;
    go_forward(100);
    servo_motor_En=0;
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
