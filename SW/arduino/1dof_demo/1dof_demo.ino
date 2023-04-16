#include <Servo.h>
Servo myservo;

String message = "0";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(20);
   
  myservo.attach(7);
  myservo.write(90);
}

void loop() {
  while (Serial.available() > 0)
  {
    message = Serial.readString();
    message.trim();
  }

  if (message == "1")
  {
    //myservo.write(85);
  }
  else if (message == "2")
  {
    //myservo.write(85);
  }
    else if (message == "q")
  {
    myservo.write(85);
  }
    else if (message == "e")
  {
    myservo.write(95);
  }
  else {
    myservo.write(90);
  }
}
