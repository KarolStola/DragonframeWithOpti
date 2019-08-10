#ifndef OPTI_200_H
#define OPTI_200_H

#include "Opti.h"

class Opti200 : public Opti
{
	virtual int GetStepsPerRevolution() override { return 16; };
};

#endif
