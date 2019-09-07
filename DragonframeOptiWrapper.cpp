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
    opti.AddBluetoothMessageHandler(new MemberBluetoothMessageHandler<DragonframeMotionController>(motionController, &DragonframeMotionController::ParseInput));
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
    return opti.IsMoving();
}

int DragonframeOptiWrapper::GetCurrentStep(int motorIndex)
{
    return opti.GetCurrentStep(motorIndex);
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
    opti.StopMoving(motorIndex);
}

void DragonframeOptiWrapper::StopAllMotors()
{
    opti.StopMoving();
}

void DragonframeOptiWrapper::SetJogSpeedForMotor(int motorIndex, int stepsPerSecond)
{
    //TODO
}

void DragonframeOptiWrapper::ZeroMotorPosition(int motorIndex)
{
    opti.ResetCurrentStep(motorIndex);
}

void DragonframeOptiWrapper::SetMotorPosition(int motorIndex, int motorPosition)
{
    opti.SetCurrentStep(motorIndex, motorPosition);
}

void DragonframeOptiWrapper::SendMessage(const String & message)
{
    opti.SendBluetoothMessage(message);
}


