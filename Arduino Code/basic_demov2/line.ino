void draw_Sun()
{
  stop_flag = 0;
  int dist = 100;

  for(int i = 0; i < 8; ++i)
  {
    EnSignal(90);
    forward(dist);
    dist += 10;
    UnSignal(90);
    right(90);
  }

  right(90);
  forward(900);

  left(45);
  forward(300);
  EnSignal(90);
  forward(200);
  UnSignal(90);


  left(45);
  backward(400);
  left(90);
  EnSignal(90);
  forward(200);
  UnSignal(90);


  left(90);
  forward(400);
  left(45);
  UnSignal(90);
  backward(200);
  EnSignal(90);

  left(45);
  backward(400);
  left(90);
  UnSignal(90);
  backward(200);
  EnSignal(90);

  left(90);
  forward(400);
  left(45);
  UnSignal(90);
  backward(200);
  EnSignal(90);
  
  stopcar();
}

void draw_Love()
{
  stop_flag=0;
  EnSignal(90);
  // 30° * 3
  for(int i = 0; i < 3; ++i)
  {
    left(30);
    forward(375);
  }

  // 45° * 2
  for(int i = 0; i < 2; ++i)
  {
    left(45);
    forward(555);
  }

  // 45°
  left(45);
  forward(1650);

  left(90);
  forward(1650);

  // 45° * 2
  for(int i = 0; i < 2; ++i)
  {
    left(45);
    forward(555);
  }

  // 30° * 3
  for(int i = 0; i < 3; ++i)
  {
    left(30);
    forward(375);
  }
  UnSignal(90);
  stopcar();
}

//void draw_Moon()
//{
//    stop_flag=0;
//    EnSignal(90);
//
//    for(int i = 0; i < 7; ++i)
//    {
//      forward(300);
//      right(25);
//    }
//
//    left(30);
//
//    for(int i = 0; i < 8; ++i)
//    {
//      backward(240);
//      left(20);
//    }
//
//    UnSignal(90);
//    stopcar();
//}

void draw_Magic()
{
  stop_flag=0;
  EnSignal(90);

  forward(250);
  
  right(110);
  forward(600);

  left(110);
  forward(750);

  left(110);
  forward(600);

  right(110);
  forward(250);

  right(60);
  
  for(int i = 0; i < 6; ++i)
  {
    left(15);
    backward(140);
  }
  
  UnSignal(90);
  stopcar();
}

void draw_King()
{
  EnSignal(90);
  forward(800);
  left(70);
  forward(370);

  right(30);
  backward(250);

  left(100);
  forward(250);

  right(100);
  backward(400);

  left(100);
  forward(250);

  right(30);
  backward(400);
  
  UnSignal(90);
  stopcar();
}


void draw_gear()
{
  stop_flag=0;
  EnSignal(90);
  
  for(int i=0; i<4;i++)
  {
      forward(300);
      left(90);

      forward(300);
      right(90);

      forward(300);
      right(90);

      forward(300);
      left(90);

      forward(300);
      right(90);
  }
  
  UnSignal(90);
  stopcar();
}


void draw_pope()
{
  stop_flag=0;
  EnSignal(90);
  backward(800);

  left(90);
  backward(100);

  right(90);
  forward(800);

  left(60);
  forward(200);

  right(105);
  forward(160);

  right(45);
  forward(250);

  right(45);
  forward(160);

  left(75);
  backward(200);

  UnSignal(90);
  stopcar();
}

void draw_priest()
{
  stop_flag=0;
  EnSignal(90);
  forward(200);

  right(90);
  forward(500);

  left(90);
  forward(500);

  right(90);
  forward(200);

  right(90);
  forward(500);

  left(90);
  forward(500);

  right(90);
  forward(200);

  right(90);
  forward(500);

  left(90);
  forward(1250);

  right(90);
  forward(200);

  right(90);
  forward(1250);

  left(90);
  forward(500);
  
  UnSignal(90);
  stopcar();
}

void draw_Tower()
{
    stop_flag=0;
    EnSignal(90);
    backward(200);

    right(10);
    backward(800);

    right(80);
    forward(300);

    right(80);
    backward(800);
    UnSignal(90);
    stopcar();
}

void draw_Star()
{
    stop_flag=0;
    EnSignal(90);
    for(int i = 0; i < 3; ++i)
    {
      forward(700);
      left(36);
      backward(700);
      left(36);
    }
    UnSignal(90);
    stopcar();
}

void draw_Moon()
{
  stop_flag=0;
  EnSignal(90);

 left(30);
 forward(1000);
 
 right(30);
 forward(1000);
 
 right(30);
 forward(1000);

 left(30);
 forward(200);

 right(30);
 backward(1000);

 
 left(30);
 backward(1000);
 
 left(30);
 backward(1100);

  stopcar();
}


void draw_circle()
{
//  EnSignal(90);
//  for(int j = 0; j < 2; ++j)
//      for(int i = 0; i < 10; ++i)
//      {
//        right(36);
//        forward(800);
//      }
//   UnSignal(90);
//    stopcar();
    EnSignal(90);
    for(int i = 0; i < 24; ++i)
    {
      go_right(200);
      forward(100);
    }
    UnSignal(90);
    stopcar();
}
