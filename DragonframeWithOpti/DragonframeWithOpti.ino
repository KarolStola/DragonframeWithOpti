#include "Arduino.h"

int LedPin = 2;
int MotorDriverActivationPin = 4;
int MotorStepPin = 16;
int MotorDirectionPin = 17;
int RightBorderSwitchPin = 33;
int LeftBorderSwitchPin = 32;
int StepsPerRevolution = 256;
const int REACHED_BORDER_THRESHOLD = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(MotorDriverActivationPin, OUTPUT);
  pinMode(MotorDirectionPin, OUTPUT);
  pinMode(MotorStepPin, OUTPUT);
  pinMode(RightBorderSwitchPin, INPUT);
  pinMode(LeftBorderSwitchPin, INPUT);
  //digitalWrite(MotorDriverActivationPin, HIGH);
}

void loop()
{
  digitalWrite(MotorDriverActivationPin, HIGH);
  digitalWrite(MotorDirectionPin, HIGH);
  digitalWrite(MotorStepPin, HIGH);
}

bool RightBorderReached()
{
  return analogRead(RightBorderSwitchPin) < REACHED_BORDER_THRESHOLD;
}

bool LeftBorderReached()
{
  return analogRead(LeftBorderSwitchPin) < REACHED_BORDER_THRESHOLD;
}
