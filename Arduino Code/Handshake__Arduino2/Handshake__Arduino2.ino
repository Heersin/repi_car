String readString;

int S_char =83;
int A_char=65;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial3.begin(9600);
   S_char=83;
   A_char=65;
}

void loop() {
  // put your main code here, to run repeatedly:
 while(!Serial3.available()){}
    while(Serial3.available()){   
        int c = Serial3.read();
        if(c == S_char){
          Serial3.write(A_char);
          Serial.write(c); 
        }
   }
   Serial.flush();
}
