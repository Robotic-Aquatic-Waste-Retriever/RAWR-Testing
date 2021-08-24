// getting input from serial monitor for motor speed
int motorPin = 3;
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
  Serial.println("But the advice 50 to 255. Because the minimum voltage required to start the motor is 50.");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 50 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
} 

// speed varies from ultrasonic distance sensor

/*

 
*/
 
