#define WE_PIN 2
#define threshold 50
volatile int count = 0;
volatile unsigned long prev = 0;

void tick() {
  unsigned long now = millis();

  if (now - prev > threshold) {
    count++;
    prev = now;
  }
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
