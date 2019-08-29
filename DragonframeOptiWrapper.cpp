#include <Opti.h>
#include <DragonframeMotionController.h>
#include <MemberBluetoothMessageHandler.h>
#include "DragonframeOptiWrapper.h"

DragonframeOptiWrapper::DragonframeOptiWrapper(Opti & opti)
    : opti(opti)
{
}

void DragonframeOptiWrapper::BindAsMessageHandler(class DragonframeMotionController & motionController)
{
    opti.AddBluetoothMessageHandler(new MemberBluetoothMessageHandler<DragonframeMotionController>(motionController, &DragonframeMotionController::HandleMessage));
}

int DragonframeOptiWrapper::GetProtocolMajorVersion()
{
    return majorVersion;
}

int DragonframeOptiWrapper::GetProtocolMinorVersion()
{
    return minorVersion;
}

int DragonframeOptiWrapper::GetProtocolFixVersion()
{
    return fixVersion;
}

int DragonframeOptiWrapper::GetNumberOfAxes()
{
    return numberOfAxes;
}

bool DragonframeOptiWrapper::GetIsMotorMoving(int motorIndex)
{
    //TODO
    return false;
}

int DragonframeOptiWrapper::GetCurrentMotorPositionInSteps(int motorIndex)
{
    //TODO
    return 0;
}

void DragonframeOptiWrapper::MoveMotorTo(int motorIndex, int stepPosition)
{
    //TODO
}

void DragonframeOptiWrapper::JogMotorTo(int motorIndex, int stepPosition)
{
    //TODO
}

void DragonframeOptiWrapper::InchMotorTo(int motorIndex, int stepPosition)
{
    //TODO
}

void DragonframeOptiWrapper::StopMotor(int motorIndex)
{
    //TODO
}

void DragonframeOptiWrapper::StopAllMotors()
{
    //TODO
}

void DragonframeOptiWrapper::SetJogSpeedForMotor(int motorIndex, int stepsPerSecond)
{
    //TODO
}

void DragonframeOptiWrapper::ZeroMotorPosition(int motorIndex)
{
    //TODO
}

void DragonframeOptiWrapper::SetMotorPosition(int motorIndex, int motorPosition)
{
    //TODO
}

void DragonframeOptiWrapper::SendMessage(const String & message)
{
    opti.SendBluetoothMessage(message);
}


