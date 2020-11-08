#pragma once
#include "Config.h"
class Output
{
	virtual void evaluate(const Matrix& previous_layer, const Matrix& target) = 0;
	virtual const Matrix& backprop_data() const = 0;
	virtual Scalar loss() const = 0;
};

