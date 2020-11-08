#pragma once
#include "Activation.h"
class Softmax: public Activation
{
	static inline void activate(const Matrix& Z, Matrix& A)
    {
        A.array() = (Z.rowwise() - Z.colwise().maxCoeff()).array().exp();
        RowArray colsums = A.colwise().sum();
        A.array().rowwise() /= colsums;
    }
    static inline void apply_jacobian(const Matrix& Z, const Matrix& A, const Matrix& F, Matrix& G)
    {
        RowArray a_dot_f = A.cwiseProduct(F).colwise().sum();
        G.array() = A.array() * (F.array().rowwise() - a_dot_f);
    }
};

