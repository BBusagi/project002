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
  myservo.write(95);
  myservo2.write(95);
  delay(2000);
  myservo.write(90);
  myservo2.write(90);
  delay(2000);
  myservo.write(100);
  myservo2.write(100);
  delay(2000);

//  myservo.write(90);
//  myservo2.write(95);
//  delay(2000);

  
}
