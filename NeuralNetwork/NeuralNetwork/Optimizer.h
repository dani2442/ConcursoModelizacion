#pragma once
#include "Config.h"
class Optimizer
{
public:
	Optimizer(){}
	virtual void update(ConstAlignedMapVec& dvec, AlignedMapVec& vec) = 0;
};

