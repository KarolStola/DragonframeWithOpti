#include "Arduino.h"
#include "Opti.h"

void Opti::Initialize()
{
	InitializeLed();
	InitializeStepper();
}

void Opti::InitializeLed()
{
	pinMode(GetLedPin(), OUTPUT);
	DeactivateLed();
}

void Opti::InitializeStepper()
{
	stepper = CreateStepper();
}

void Opti::Cleanup()
{
	DeactivateLed();
}

void Opti::ActivateLed()
{
	SetLedActive(true);
}

void Opti::DeactivateLed()
{
	SetLedActive(false);
}

void Opti::SetLedActive(bool Value)
{
	digitalWrite(GetLedPin(), Value ? HIGH : LOW);
}

bool Opti::RightBorderReached()
{
	return IsBumped(GetRightBumperPin());
}

bool Opti::LeftBorderReached()
{
	return IsBumped(GetLeftBumperPin());
}

bool Opti::IsBumped(int BumperPin)
{
	return analogRead(BumperPin) < GetBumpValueThreshold();
}

Opti::~Opti()
{
	Cleanup();
}
