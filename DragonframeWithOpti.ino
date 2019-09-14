#include <Arduino.h>
#include <Opti200.h>
#include <DragonframeMotionController.h>
#include "DragonframeOptiWrapper.h"

Opti200 opti(Serial1);
DragonframeOptiWrapper dragonframeOptiWrapper(opti);
DragonframeMotionController dragonframeMotionController(dragonframeOptiWrapper);

void setup()
{
	Serial.begin(9600);
	opti.Initialize();
}

void loop()
{
	opti.Update();
	dragonframeMotionController.Update();
}

