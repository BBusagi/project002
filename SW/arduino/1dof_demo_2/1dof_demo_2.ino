String string;
int timedelay = 550;
#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(20);
  myservo.attach(9);//servo 3
  myservo.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    string = Serial.readString();
    string.trim();
    if (string == "1")
    {
      clockwise(myservo);
    }
    else if (string == "2")
    {
      anticlockwise(myservo);
    }
    else if (string == "3")
    {
      clockwise(myservo);
    }
    else if (string == "4")
    {
      anticlockwise(myservo);
    }
    else  {
      myservo.write(90);
    }
  }
  else
  { }
}

void clockwise(Servo servoname)
{ servoname.write(180);
  delay(100);
}

void anticlockwise(Servo servoname)
{ 
  servoname.write(0);
  delay(100);
}
