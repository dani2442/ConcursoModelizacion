#pragma once
#include "Activation.h"
class Sigmoid: public Activation 
{
	static void activate(const Matrix& Z, Matrix& A) {
		A.array() = Scalar(1) / (Scalar(1) + (-Z.array()).exp());
	}
	static void apply_jacobian(const Matrix& Z, const Matrix& A, const Matrix& F, Matrix& G) {
		G.array() = A.array() * (Scalar(1) - A.array()) * F.array();
	}
};

