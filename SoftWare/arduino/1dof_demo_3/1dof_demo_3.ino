String string;
int timedelay = 550;
#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(20);
  myservo.attach(7);//servo 1
  myservo2.attach(9);//servo 2
  myservo.write(90);
  myservo2.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    string = Serial.readString();
    string.trim();
    if (string == "1")
    {
      //clockwise(myservo);
    }
    else if (string == "2")
    {
      //anticlockwise(myservo);
    }
    else if (string == "3")
    {
      //clockwise(myservo2);
      clockwise(myservo);
    }
    else if (string == "4")
    {
      //anticlockwise(myservo2);
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
{ servoname.write(70);
  delay(timedelay);
  servoname.write(90);
}
void clockwise2(Servo servoname)
{ servoname.write(80);
  delay(timedelay/5);
  servoname.write(90);
  delay(timedelay/10);
  servoname.write(80);
  delay(timedelay/5);
  servoname.write(90);
}

void anticlockwise(Servo servoname)
{ servoname.write(100);
  delay(timedelay);
  servoname.write(90);
}
