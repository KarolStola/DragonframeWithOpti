#include <Arduino.h>
#include <HardwareSerial.h>
#include "OptiStepperTMC2208.h"

OptiStepperTMC2208::OptiStepperTMC2208(int driverActivationPin, int stepPin, int stepDirectionPin, HardwareSerial * serial, int baudRate)
	: driverActivationPin(driverActivationPin)
	, stepPin(stepPin)
	, stepDirectionPin(stepDirectionPin)
	, baudRate(baudRate)
	, serial(serial)
	, driver(TMC2208Stepper(serial))
{
	Initialize();
}

void OptiStepperTMC2208::Initialize()
{
	serial->begin(baudRate);
	driver.push();                // Reset registers

	pinMode(driverActivationPin, OUTPUT);
	pinMode(stepPin, OUTPUT);
	
	DeactivateDriver();

	driver.pdn_disable(true);     // Use PDN/UART pin for communication
	driver.I_scale_analog(false); // Use internal voltage reference
	driver.rms_current(1400);     // Set driver current 1400mA
	driver.toff(2);               // Enable driver in software
}

void OptiStepperTMC2208::ActivateDriver()
{
	SetDriverActive(true);
}

void OptiStepperTMC2208::DeactivateDriver()
{
	SetDriverActive(false);
}

void OptiStepperTMC2208::SetDriverActive(bool value)
{
	digitalWrite(driverActivationPin, value ? LOW : HIGH);
}
