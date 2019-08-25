#ifndef DRAGONFRAME_OPTI_WRAPPER_H
#define DRAGONFRAME_OPTI_WRAPPER_H

#include <DragonframeDevice.h>

class DragonframeOptiWrapper : public DragonframeDevice
{
public:
    DragonframeOptiWrapper(class Opti * opti);

    virtual int GetMajorVersion() override;
    virtual const String & GetFullVersion() override;
    virtual int GetNumberOfAxes() override;
    virtual void SendMessage(const String & message) override;
    virtual void BindAsMessageHandler(class DragonframeMotionController * motionController) override;


private:
    class Opti * opti = nullptr;

    const int majorVersion = 1;
    const String fullVersion = "1.3.0";
    const int numberOfAxes = 1;
};

#endif