#define WE_PIN 2    //Pin for the Speed Encoder Digital Out

volatile int count = 0;


void tick() {

    count++;

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode( WE_PIN, INPUT);
  attachInterrupt( digitalPinToInterrupt( WE_PIN), tick, RISING );
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Count = ");
  Serial.println(count);
}
