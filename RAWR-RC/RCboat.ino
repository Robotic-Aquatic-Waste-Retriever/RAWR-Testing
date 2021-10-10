#include<Servo.h>
#define MOTOROFF 1000
#define MOTORONRIGHT 1300
#define MOTORONLEFT 1500

Servo LEFT; // left motor
Servo RIGHT; // right motor

void setup() {
  LEFT.attach(8);
  RIGHT.attach(4);
  LEFT.writeMicroseconds(1000);
  RIGHT.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  int leftVal;
  int rightVal;
  int leftOn;
  int rightOn;
  

  

  leftVal = analogRead(A0);
  rightVal = analogRead(A2);

  leftVal = map(leftVal, 0, 1023, 1000, 2000);
  rightVal = map(rightVal, 0, 1023, 1000, 2000);

  if(leftVal > 1010 && rightVal > 1010) // FORWARD
  {
    LEFT.writeMicroseconds(MOTORONLEFT);
    //delay(100);
    RIGHT.writeMicroseconds(MOTORONRIGHT);
    Serial.print("leftVal = ");
    Serial.print(leftVal);
    Serial.print("  rightVal = ");
    Serial.print(rightVal);
    Serial.println(" FORWARD");
  }
  else if (leftVal < 1010 && rightVal > 1010) //LEFT TURN
  {
    LEFT.writeMicroseconds(MOTOROFF);
    //delay(100);
    RIGHT.writeMicroseconds(MOTORONRIGHT);
    Serial.print("leftVal = ");
    Serial.print(leftVal);
    Serial.print("  rightVal = ");
    Serial.print(rightVal);
    Serial.println(" LEFT");
  }
  else if (leftVal > 1010 && rightVal < 1010) // RIGHT TURN
  {
    LEFT.writeMicroseconds(MOTORONLEFT);
    //delay(100);
    RIGHT.writeMicroseconds(MOTOROFF);
    Serial.print("leftVal = ");
    Serial.print(leftVal);
    Serial.print("  rightVal = ");
    Serial.print(rightVal);
    Serial.println(" RIGHT");
  }
  else // STOPPED
  {
    LEFT.writeMicroseconds(MOTOROFF);
    //delay(100);
    RIGHT.writeMicroseconds(MOTOROFF);
    Serial.print("leftVal = ");
    Serial.print(leftVal);
    Serial.print("  rightVal = ");
    Serial.print(rightVal);
    Serial.println(" STOPPED");
  }

  //Serial.print("leftOn = ");
  //Serial.print(leftOn);
  //Serial.print("  rightOn = ");
  //Serial.println(rightOn);

  delay(500);
  

}
