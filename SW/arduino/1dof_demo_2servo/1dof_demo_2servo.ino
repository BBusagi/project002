String string;
int timedelay = 550;
#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(20);
  myservo.attach(7);
  myservo2.attach(9);
  myservo.write(95);
  myservo2.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    string = Serial.readString();
    string.trim();
    if (string == "1")
    {
      clockwise();
      //clockwise(myservo2);
    }
    else if (string == "2")
    {
      anticlockwise();
      //anticlockwise(myservo2);
    }
    else if (string == "3")
    {
      //clockwise(myservo2);
    }
    else if (string == "4")
    {
      //anticlockwise(myservo2);
    }
    else  {
      myservo.write(95);
    }
  }
  else
  { }
}

void clockwise()
{ myservo.write(70);
  myservo2.write(70);
  delay(timedelay);
  myservo.write(90);
  myservo2.write(90);
}

void anticlockwise()
{ myservo.write(110);
  myservo2.write(110);
  delay(timedelay);
  myservo.write(90);
  myservo2.write(90);
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
