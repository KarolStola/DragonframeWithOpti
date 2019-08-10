#include "Arduino.h"
#include "Opti.h"

bool Opti::IsInitialized = false;

Opti::Opti()
{
	EnsureInitialization();
}

Opti::~Opti()
{
	Cleanup();
}

void Opti::EnsureInitialization()
{
	if (!IsInitialized)
	{
		Initialize();
	}
}

void Opti::Initialize()
{
	SetupPins();
	IsInitialized = true;
}

void Opti::SetupPins()
{
	pinMode(GetLedPin(), OUTPUT);
}

void Opti::Cleanup()
{
	TurnLedOff();
}

void Opti::TurnLedOn()
{
	SetLedOn(true);
}

void Opti::TurnLedOff()
{
	SetLedOn(false);
}

void Opti::SetLedOn(bool Value)
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
