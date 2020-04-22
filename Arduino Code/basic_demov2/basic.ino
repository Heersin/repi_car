void forward(int distance)
{
  std_forward(distance);  
}

void backward(int distance)
{
  std_backward(distance);
}

void right(int angle)
{
    readheading();
    set_ang = heading + angle;
    checkdirection(set_ang);
}


void left(int angle)
{
    readheading();
    set_ang = heading - angle;
    checkdirection(set_ang);
}

void testcase()
{
  forward(1200);
  backward(800);
  right(45);
  forward(900);
  left(90);
  backward(500);
  stopcar();
}
