#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(20);
   
  myservo.attach(7);
  myservo2.attach(9);

}

void loop() {
  //myservo.write(90);  myservo2.write(90);
  myservo.write(70);  //myservo2.write(85);
}
