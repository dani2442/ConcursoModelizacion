#pragma once
#include "Matrix.h"

class Activation
{
	virtual void activate(const Matrix& Z, Matrix& A) = 0;

	virtual void jacobian(const Matrix& Z, const Matrix& A, const Matrix& F, Matrix G) = 0;
};

