#pragma once
#include "Config.h"
class Activation
{
	static void activate(const Matrix& Z, Matrix& A) {};

	static void jacobian(const Matrix& Z, const Matrix& A, const Matrix& F, Matrix G) {};
};

