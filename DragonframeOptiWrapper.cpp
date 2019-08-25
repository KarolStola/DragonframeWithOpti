#include <Opti.h>
#include <DragonframeMotionController.h>
#include <MemberBluetoothMessageHandler.h>
#include "DragonframeOptiWrapper.h"

DragonframeOptiWrapper::DragonframeOptiWrapper(Opti * opti)
    : opti(opti)
{
}

int DragonframeOptiWrapper::GetMajorVersion()
{
    return majorVersion;
}

const String & DragonframeOptiWrapper::GetFullVersion()
{
    return fullVersion;
}

int DragonframeOptiWrapper::GetNumberOfAxes()
{
    return numberOfAxes;
}

void DragonframeOptiWrapper::SendMessage(const String & message)
{
    opti->SendBluetoothMessage(message);
}

void DragonframeOptiWrapper::BindAsMessageHandler(class DragonframeMotionController * motionController)
{
    opti->AddBluetoothMessageHandler(new MemberBluetoothMessageHandler<DragonframeMotionController>(motionController, &DragonframeMotionController::HandleMessage));
}
