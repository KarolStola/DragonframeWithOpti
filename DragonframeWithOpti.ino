#include <Arduino.h>
#include <Opti200.h>
#include <DelayedTaskManager.h>
#include <DelayedMemberTask.h>
#include <MemberBluetoothMessageHandler.h>
#include <DragonframeMotionController.h>
#include "DragonframeOptiWrapper.h"

Opti200 opti;
DragonframeMotionController dragonframeMotionController;

void setup()
{
	Serial.begin(9600);
	opti.Initialize(&Serial1);
	dragonframeMotionController.Initialize(new DragonframeOptiWrapper(opti));
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


