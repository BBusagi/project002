#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(20);
   
  myservo.attach(7);
  myservo.write(90);
}

void loop() {
//  myservo.write(90);
//  delay(1000);
  myservo.write(120);
  delay(5000);
}
