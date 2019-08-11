#ifndef OPTI_STEPPER_TMC2208_H
#define OPTI_STEPPER_TMC2208_H

#include <TMC2208Stepper.h>
#include "OptiStepper.h"

class OptiStepperTMC2208 : public OptiStepper
{
public:
	OptiStepperTMC2208(int driverActivationPin, int stepPin, int stepDirectionPin, HardwareSerial * serial, int baudRate);

private:
	void Initialize();

	void ActivateDriver();
	void DeactivateDriver();
	void SetDriverActive(bool Value);
	
	const int driverActivationPin;
	const int stepPin;
	const int stepDirectionPin;
	const int baudRate;
	HardwareSerial * const serial;
	TMC2208Stepper driver;
};

#endif
