String string;
String previString;

int timedelay = 205;
#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(20);
  myservo.attach(7);
  myservo2.attach(9);
  myservo.write(90);
  myservo2.write(90);
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
      clockwise(myservo2);
    }
    else if (string == "4")
    {
      anticlockwise(myservo2);
    }
    else  {
      myservo.write(90);
    }

    previString = string;
  }
  else
  {
    myservo.write(90);
    }
}

void clockwise(Servo servoname)
{ if(previString != string)
  {
    stopServo(myservo);
    stopServo(myservo2);
    }
  servoname.write(70);
  delay(timedelay);

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
{ if(previString != string)
  {
    stopServo(myservo);
    stopServo(myservo2);
    }
  servoname.write(105);
  delay(timedelay);
}

void stopServo (Servo servoname)
{ 
  servoname.write(90);
  delay(1);
  }
