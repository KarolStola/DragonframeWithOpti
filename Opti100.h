#ifndef OPTI_100_H
#define OPTI_100_H

#include "Opti.h"

class Opti100 : public Opti
{
	virtual int GetStepsPerRevolution() override { return 16; };
};

#endif
