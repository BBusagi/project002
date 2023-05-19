String string;
String previString;
String directionMes;
int direction;
String speedMes;
int speed;

int timedelay = 205;
#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(20);
  myservo.attach(7);
  //myservo2.attach(9);
  myservo2.attach(10);
  stopServo();
}

void loop() {
  if (Serial.available() > 0) {
    string = Serial.readString();
    string.trim();    
    int index = string.indexOf(";");
    directionMes = string.substring(0, index);
    direction = directionMes.toInt();
    speedMes = string.substring(index + 1);
    speed = speedMes.toInt();
    
    if (direction == 1)
    {
      clockwise(myservo,speed);
    }
    else if (direction == 2)
    {
      anticlockwise(myservo,speed);
    }
    else if (direction == 3)
    {
      clockwise(myservo2);
    }
    else if (direction == 4)
    {
      anticlockwise(myservo2);
    }
    else  {
      stopServo();
    }
    previString = string;
  }
  else
  {
    stopServo();
    }
}

void clockwise(Servo servoname)
{ if(previString != string)
  {
    stopServo();
    }
  servoname.write(80);
  delay(timedelay);
}

void clockwise(Servo servoname,int speed)//带速度控制
{ if(previString != string)
  {
    stopServo();
    }
  servoname.write(90-speed*5);//变速处理
  delay(timedelay);

}

//void clockwise2(Servo servoname)
//{ servoname.write(80);
//  delay(timedelay/5);
//  servoname.write(90);
//  delay(timedelay/10);
//  servoname.write(80);
//  delay(timedelay/5);
//  servoname.write(90);
//}

void anticlockwise(Servo servoname)
{ if(previString != string)
  {
    stopServo();
    }
  servoname.write(110);
  delay(timedelay);
}

void anticlockwise(Servo servoname,int speed)
{ if(previString != string)
  {
    stopServo();
    }
  servoname.write(90 +speed*10);//变速处理
  delay(timedelay);
}

void stopServo ()
{ 
  myservo.write(90);//servo的中间值
  delay(1);
  myservo2.write(95);//servo2的中间值
  delay(1);
  }
