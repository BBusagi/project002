#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(20);
   
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  myservo.write(-90);
  delay(2000);
  myservo.write(200);
  delay(2000);
}
