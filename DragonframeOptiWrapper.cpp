#include <Opti.h>
#include <DragonframeMotionController.h>
#include <MemberBluetoothMessageHandler.h>
#include "DragonframeOptiWrapper.h"

DragonframeOptiWrapper::DragonframeOptiWrapper(Opti & opti)
    : opti(opti)
{
    jogSpeeds.resize(GetNumberOfAxes(), standardSpeed);
    jogStatuses.resize(GetNumberOfAxes(), false);
}

void DragonframeOptiWrapper::BindAsMessageHandler(class DragonframeMotionController & motionController)
{
    opti.SetBluetoothMessageDelimiter(motionController.GetIncomingMessageDelimiter());
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
    return opti.GetMotorCount();
}

bool DragonframeOptiWrapper::GetIsMotorMoving(int motorIndex)
{
    return opti.IsMoving(ToOptiIndex(motorIndex));
}

int DragonframeOptiWrapper::GetCurrentStep(int motorIndex)
{
    return opti.GetCurrentStep(ToOptiIndex(motorIndex));
}

void DragonframeOptiWrapper::MoveMotorTo(int motorIndex, int stepPosition)
{
    SetIsJogging(motorIndex, false);
    SetStepsPerSecond(motorIndex, standardSpeed);
    MoveTo(motorIndex, stepPosition);
}

void DragonframeOptiWrapper::JogMotorTo(int motorIndex, int stepPosition)
{
    SetIsJogging(motorIndex, true);
    MoveTo(motorIndex, stepPosition);
}

void DragonframeOptiWrapper::InchMotorTo(int motorIndex, int stepPosition)
{
    SetIsJogging(motorIndex, false);
    SetStepsPerSecond(motorIndex, inchingSpeed);
    MoveTo(motorIndex, stepPosition);
}

void DragonframeOptiWrapper::StopMotor(int motorIndex)
{
    opti.StopMoving(ToOptiIndex(motorIndex));
}

void DragonframeOptiWrapper::StopAllMotors()
{
    opti.StopMovingAll();
}

void DragonframeOptiWrapper::SetJogSpeedForMotor(int motorIndex, int stepsPerSecond)
{
    jogSpeeds[ToOptiIndex(motorIndex)] = stepsPerSecond;

    if(IsJogging(motorIndex))
    {
        SetStepsPerSecond(motorIndex, stepsPerSecond);
    }
}

void DragonframeOptiWrapper::ZeroMotorPosition(int motorIndex)
{
    opti.ResetCurrentStep(ToOptiIndex(motorIndex));
}

void DragonframeOptiWrapper::SetMotorPosition(int motorIndex, int motorPosition)
{
    opti.SetCurrentStep(ToOptiIndex(motorIndex), motorPosition);
}

void DragonframeOptiWrapper::SendMessage(const String & message)
{
    opti.SendBluetoothMessage(message);
}

void DragonframeOptiWrapper::SetIsJogging(int motorIndex, bool value)
{
    jogStatuses[ToOptiIndex(motorIndex)] = value;
    if(value)
    {
        SetStepsPerSecond(motorIndex, GetJogSpeed(motorIndex));
    }
}

bool DragonframeOptiWrapper::IsJogging(int motorIndex)
{
    return jogStatuses[ToOptiIndex(motorIndex)];
}

int DragonframeOptiWrapper::ToOptiIndex(int dragondrameIndex)
{
    return dragondrameIndex - 1;
}

void DragonframeOptiWrapper::SetStepsPerSecond(int motorIndex, int stepsPerSecond)
{
    opti.SetStepsPerSecond(ToOptiIndex(motorIndex), stepsPerSecond);
}

int DragonframeOptiWrapper::GetJogSpeed(int motorIndex)
{
    return jogSpeeds[ToOptiIndex(motorIndex)];
}

void DragonframeOptiWrapper::MoveTo(int motorIndex, long stepPosition)
{
    opti.MoveTo(ToOptiIndex(motorIndex), stepPosition);
}



