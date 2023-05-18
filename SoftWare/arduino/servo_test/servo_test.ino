#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(20);
   
  //myservo.attach(9);
  myservo2.attach(10);

}

void loop() {
  //myservo.write(100);
  myservo2.write(100);
  delay(1000);
}
