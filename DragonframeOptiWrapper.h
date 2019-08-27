#ifndef DRAGONFRAME_OPTI_WRAPPER_H
#define DRAGONFRAME_OPTI_WRAPPER_H

#include <DragonframeDevice.h>

class DragonframeOptiWrapper : public DragonframeDevice
{
public:
    DragonframeOptiWrapper(class Opti & opti);

    virtual const char * GetMajorVersion() override;
    virtual const char * GetFullVersion() override;
    virtual const char * GetNumberOfAxes() override;
    virtual void SendMessage(const String & message) override;
    virtual void BindAsMessageHandler(class DragonframeMotionController & motionController) override;


private:
    class Opti & opti;

    const char * numberOfAxes = "1";
    const char * majorVersion = "1";
    const char * fullVersion = "1.3.0";
};

#endif