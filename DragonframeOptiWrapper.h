#ifndef DRAGONFRAME_OPTI_WRAPPER_H
#define DRAGONFRAME_OPTI_WRAPPER_H

#include <DragonframeDevice.h>

class DragonframeOptiWrapper : public DragonframeDevice
{
public:
    DragonframeOptiWrapper(class Opti & opti);

    virtual void BindAsMessageHandler(class DragonframeMotionController & motionController) override;

    virtual int GetProtocolMajorVersion() override;
    virtual int GetProtocolMinorVersion() override;
    virtual int GetProtocolFixVersion() override;
    virtual int GetNumberOfAxes() override;
    virtual int GetCurrentStep(int motorIndex) override;
    virtual bool GetIsMotorMoving(int motorIndex) override;

    virtual void MoveMotorTo(int motorIndex, int stepPosition) override;
    virtual void JogMotorTo(int motorIndex, int stepPosition) override;
    virtual void InchMotorTo(int motorIndex, int stepPosition) override;
    virtual void StopMotor(int motorIndex) override;
    virtual void StopAllMotors() override;
    virtual void SetJogSpeedForMotor(int motorIndex, int stepsPerSecond) override;
    virtual void ZeroMotorPosition(int motorIndex) override;
    virtual void SetMotorPosition(int motorIndex, int motorPosition) override;
    virtual void SendMessage(const String & message) override;


private:
    void SetIsJogging(int motorIndex, bool value);
    bool IsJogging(int motorIndex);
    void SetStepsPerSecond(int motorIndex, int stepsPerSecond);
    int ToOptiIndex(int dragondrameIndex);
    int GetJogSpeed(int motorIndex);
    void MoveTo(int motorIndex, long stepPosition);

    class Opti & opti;
    const int numberOfAxes = 1;
    const int majorVersion = 1;
    const int minorVersion = 3;
    const int fixVersion = 0;
    const int inchingSpeed = 10;
    const int standardSpeed = 30;

    std::vector<int> jogSpeeds;
    std::vector<bool> jogStatuses;
};

#endif