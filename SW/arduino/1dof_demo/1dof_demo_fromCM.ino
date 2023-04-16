int inByte;
String string;
//String LH_C;

#include <Servo.h>
Servo myservo;

const int LED = 13;

const int dirPin1 = 2;  // Direction
const int stepPin1 = 3; // Step

const int dirPin2 = 5;  // Direction
const int stepPin2 = 6; // Step

const int STEPS_PER_REV = 100;
const int speed_M = 500;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);
    myservo.attach(7);
  // put your setup code here, to run once:
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);

  pinMode(LED, OUTPUT); 
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
      //if (true) {
    // get incoming byte:
    
    //inByte = Serial.read();    
    string = Serial.readString();
    string.trim();
    if (string == "1")  
    {Motor_1(HIGH);
    delay(100);
    Motor_1(LOW);
    }
    else if (string == "2")  
    {Motor_2(HIGH);
    delay(100);
    Motor_2(LOW);
    }
    else if (string == "q")  
    {myservo.write(85);
    }
    else if (string == "e")  
    {myservo.write(95);
    }
    else  {blinkError();}
  }
  else
  { blinkNormal();}

  
//  if ()
//  {Motor_1();}
//  else if()
//  {Motor_2();}
}

//Right Motor
void Motor_1(int LH)//单次运行
{
  digitalWrite(dirPin1,LH); //shorten
  for(int x = 0; x < STEPS_PER_REV*2; x++) //运行速度
  {
    SlowSpinSimple1();
    }
  }

//Left Motor
void Motor_2(int LH)//simple
{
  digitalWrite(dirPin2,LH); //shorten
  for(int x = 0; x < STEPS_PER_REV; x++) //运行速度
  {
    SlowSpinSimple2();
    }
  }

void SlowSpinSimple1()//inner
{
  digitalWrite(stepPin1,HIGH); 
  delayMicroseconds(speed_M); 
  digitalWrite(stepPin1,LOW); 
  delayMicroseconds(speed_M);
  }
  
void SlowSpinSimple2()//inner
 {
  digitalWrite(stepPin2,HIGH); 
  delayMicroseconds(speed_M); 
  digitalWrite(stepPin2,LOW); 
  delayMicroseconds(speed_M);
  }


void blinkNormal() 
{
 digitalWrite(LED, HIGH);   
 delay(1000);                       
 digitalWrite(LED, LOW);   
 delay(1000); 
}  


void blinkError() 
{
 digitalWrite(LED, HIGH);   
 delay(50);                       
 digitalWrite(LED, LOW);   
 delay(50); 
} 
