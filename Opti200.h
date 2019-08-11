#ifndef OPTI_200_H
#define OPTI_200_H

#include "Opti.h"

class Opti200 : public Opti
{
	virtual OptiStepper CreateStepper() override;
};

#endif
