#pragma once
#include "Optimizer.h"
#include "Config.h"

// Stockastic Gradient Descent
class SGD: public Optimizer
{
public:
	Scalar l_rate; // Learning rate
	SGD(Scalar l_rate=0.01):l_rate(l_rate){}

	void update(ConstAlignedMapVec& dvec, AlignedMapVec& vec) {
		vec.noalias() -= l_rate*dvec;
	}
};

