#include <Arduino.h>
#include <Opti200.h>
#include <DelayedTaskManager.h>
#include <DelayedMemberTask.h>
#include <MemberBluetoothMessageHandler.h>
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
}

void DebugStepperDirectionChange()
{
	if(opti.LeftBorderReached())
	{
		opti.SetMovementDirection(MovementDirection::Left);
	}
	else if(opti.RightBorderReached())
	{
		opti.SetMovementDirection(MovementDirection::Right);
	}
}


