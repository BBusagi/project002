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
  //myservo.write(115);
  myservo.write(95);
}
