#pragma once
#include "Output.h"
#include "Config.h"

class RegressionMSE: public Output
{
private:
	Matrix d_in;
public:
	void evaluate(const Matrix& previous_layer, const Matrix& target) {
		const __int64 s_batch = previous_layer.cols(),s_output=previous_layer.rows();
		d_in.resize(s_output, s_batch);
		d_in.noalias() = previous_layer - target;
	}

	const Matrix& backprop_data() const { return d_in; }

	Scalar loss() const { return d_in.squaredNorm() / d_in.cols() * Scalar(0.5); }
};

