#include <QMC5883L.h>
#include <Wire.h>

QMC5883L compass;


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

void checkdirection(int set_ang){
  const int eps_ang = 20;
  const int KP = 1;
  uint8_t turn_speed = 0;
  Serial.println("Enter this function");
  if((stop_flag == 0)){
    Serial.println("Hello");
    readheading();
    int delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
    while (delta > eps_ang || delta < -eps_ang){
      Serial.println(heading);
      Serial.println("Adjusting....");
      if ((delta >=0 )&&(delta <= 180)) {
        while((delta > 0)&&(delta <= 180)){            
          readheading();
          delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
          turn_speed = abs(KP*(heading - 180))>>4;
          go_right(180);
          
        }          
      }
      else {
        while((delta < 0)&&(delta >= -180)) {
           readheading();
           delta = heading - set_ang; if (delta > 180) delta -= 360; else if (delta <= -180) delta += 360;
           turn_speed = abs(KP*(heading - 180))>>4;
           go_left(180);
        }
      }      

    }
  }
  Serial.println("stop_flag is 1");
  
}
