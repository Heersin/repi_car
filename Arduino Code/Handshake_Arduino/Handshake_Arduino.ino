String readString;
String data;
String flag;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 while(!Serial.available()){}
    while(Serial.available()){
      if(Serial.available()>0){
        int c = Serial.read();
        readString += c;
      }
   }

   if (readString.length()>0){
    flag = "True";
    data=flag+"-"+readString;
    Serial.println(data);
    readString="";
    delay(200);
   }
   Serial.flush();
}
