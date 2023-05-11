//串口信息
const int BAUD_RATE = 115200;
String message;
int indexP, indexR;
float vertical, horizontal;

//舵机信息
#include <Servo.h>
Servo myservo;
int pos;
int speed = 5;

void setup() {
  Serial.begin(BAUD_RATE);

  myservo.attach(7);
  myservo.write(0);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // 检查串口是否有数据可读
  if (Serial.available() > 0) {
    message = Serial.readString();
    horizontal = message.toFloat();
    // 解析垂直和水平输入信息
//    indexP = message.indexOf("P ");
//    indexR = message.indexOf(" R ");
//    if (indexP != -1 && indexR != -1) {
//      vertical = message.substring(indexP + 2, indexR).toFloat();
//      horizontal = message.substring(indexR + 3).toFloat();
//    }
   }
   else{    myservo.write(90);}
    // 处理垂直和水平输入信息
    //Serial.println(vertical);
    //Serial.println(horizontal);

    if (horizontal > 0)
    {
      turnRight();
    }
    else if (horizontal < 0)
    {
      turnLeft();
    }
}

void turnLeft ()
{
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(speed);                       // waits 15 ms for the servo to reach the position
  }
}

void turnRight ()
{
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(speed);                       // waits 15 ms for the servo to reach the position
  }
}

void blink(int speed)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(speed);
  digitalWrite(LED_BUILTIN, LOW);
  delay(speed);
}

void error()
{
  digitalWrite(LED_BUILTIN, HIGH);
}
