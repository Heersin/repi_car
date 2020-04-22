#include <QMC5883L.h>
#include <Wire.h>

QMC5883L compass;

int heading = 0;
boolean directionSet = 0;

void compassset()
{
  Wire.begin();
  
  compass.init();
  compass.setSamplingRate(50);
}

void readheading()
{
  heading = compass.readHeading();
}


extern uint8_t RF_CUR, RF_EN;
extern uint8_t LF_CUR, LF_EN;
extern uint8_t RB_CUR, RB_EN;
extern uint8_t LB_CUR, LB_EN;
extern boolean Running;
void checkdirection(int set_ang){
  const int eps_ang = 20;
  const int KP = 1;
  uint8_t turn_speed = 0;
  LF_EN = 1;RF_EN = 1;LB_EN = 1;RB_EN = 1; 
  Motor_save();   
  if(Running && directionSet){
    Serial.println("Hello");
    readheading();
    Serial.println(heading);
    int delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
    while (delta > eps_ang || delta < -eps_ang){
      Serial.println("Hello");
      if ((delta >=0 )&&(delta <= 180)) {
        while((delta > 0)&&(delta <=180)){            
          readheading();
          
          delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
          turn_speed = abs(KP*(heading - 180))>>4;
          go_right(200);
          
        }          
      }
      else {
        while((delta < 0)&&(delta >= -180)) {
           readheading();
           delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
           turn_speed = abs(KP*(heading - 180))>>4;
           go_left(200);
        }
      }      

    }
    Motor_recover();
  }
}
