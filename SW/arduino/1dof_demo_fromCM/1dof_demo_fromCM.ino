String string;

#include <Servo.h>
Servo myservo;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);
  myservo.attach(7);
}

void loop() {
  if (Serial.available() > 0) {  
    string = Serial.readString();
    string.trim();
    if (string == "1")  
    {myservo.write(85);}
    else if (string == "2")  
    {myservo.write(95);}
    else if (string == "3")  
    {myservo.write(95);}
    else if (string == "4")  
    {myservo.write(85);}
    else  {myservo.write(90);}
  }
  else
  { }
}
  
