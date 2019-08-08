int LedPin = 2;
int MotorStepPin = 16;
int MotorDirectionPin = 17;
int MotorDriverActivationPin = 4;
int RightBorderSwitch = 33;
int LeftBorderSwitch = 32;

void setup()
{
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(MotorDriverActivationPin, OUTPUT);
  pinMode(MotorDirectionPin, OUTPUT);
  pinMode(MotorStepPin, OUTPUT);
  pinMode(RightBorderSwitch, INPUT);
  pinMode(LeftBorderSwitch, INPUT);
  //digitalWrite(MotorDriverActivationPin, HIGH);
}

void loop()
{
  if(analogRead(RightBorderSwitch) == 0.f)
  {
    digitalWrite(LedPin, HIGH);
    //Serial.println("pressed");
  }
  else
  {
    digitalWrite(LedPin, LOW);
  }
  //Serial.println(analogRead(LeftBorderSwitch));
  //delay(500);
  
  /*rightBorderReached = digitalRead(RightBorderSwitch);
  if(rightBorderReached != 0 || test == 1)
  {
    test = 1;
    digitalWrite(LedPin, HIGH);
  }*/
  
  /*digitalWrite(LedPin, HIGH);
  delay(400);
  digitalWrite(LedPin, LOW);
  delay(400);*/
  
}
