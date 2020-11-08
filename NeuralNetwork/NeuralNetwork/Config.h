#pragma once
#include <Eigen/Core>

// Number type used in Neural Network
typedef double Scalar;

typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;
typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

typedef Vector::ConstAlignedMapType ConstAlignedMapVec;
typedef Vector::AlignedMapType AlignedMapVec;

typedef Eigen::Array<Scalar, 1, Eigen::Dynamic> RowArray;