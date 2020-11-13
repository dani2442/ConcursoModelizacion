#pragma once
#include "Config.h"
#include "Random.h"
#include "Optimizer.h"
#include <Eigen/Core>
#include <string>

class Layer
{
protected:
	const int in_size, out_size;

public:
	Layer() :in_size(-1), out_size(-1) {}
	Layer(const int in_size,const int out_size):in_size(in_size),out_size(out_size){}

	virtual void init(const Scalar& mu, const Scalar& sigma, RNG& rng) = 0;
	virtual void forward(const Matrix& previous_layer) = 0;
	virtual void backward(const Matrix& previous_layer, const Matrix& next_layer) = 0;
	virtual const Matrix& get_backward_data() const = 0;
	virtual void update(Optimizer& opt) = 0;
};


enum ModeLayer
{
	Valid=0, Same=1, Full=2
};
