#pragma once
#include "Config.h"
#include "Random.h"
#include "Matrix.h"
#include "Optimizer.h"

class Layer
{
	Layer(const int in_size,const int out_size){}

	virtual void init(const Scalar& mu, const Scalar& sigma, RNG& rng) = 0;
	virtual void forward(const Matrix& previous_layer) = 0;
	virtual void backward(const Matrix& previous_layer, const Matrix& next_layer) = 0;
	virtual const Matrix& get_backward_data() const = 0;
	virtual void update(Optimizer& opt) = 0;
};

