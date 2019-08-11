#define EN_PIN 4
#define STEP_PIN 16
#include "Opti200.h"

Opti200 opti;

void setup()
{
	opti.Initialize();
	digitalWrite(EN_PIN, LOW);
}

void loop()
{
	digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
	delayMicroseconds(100);
}
