//This code does not accomidate real-time data

//Constant Resources
#define outputPin 6

//Variable Resources
String serialInput;

void setup()
{
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
}

void loop()
{
  if (Serial.available())
  {
    delay(10);
    serialInput = Serial.readString();

    serialInput.trim();
    if(serialInput.compareTo("True") == 0){digitalWrite(outputPin, HIGH); Serial.println("Here too");}
    else{digitalWrite(outputPin, LOW);}
    Serial.flush();

  }
}
