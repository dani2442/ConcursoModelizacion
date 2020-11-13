#include "Config.h"
#include "NeuralNet.h"
#include "Layer.h"
#include <iostream>

#include <Eigen/Core>
#include <chrono> 
#include <ctime>
#include <unsupported/Eigen/CXX11/Tensor>

 
int main() {
	Eigen::Tensor<Scalar,3>a(2, 2, 3);
	a(0, 0, 0) = 0;
	a(1, 0, 0) = 1;
	a(0, 1, 0) = 2;
	a(1, 1, 0) = 3;
	a(0, 0, 1) = 4;
	a(1, 0, 1) = 5;
	a(0, 1, 1) = 6;
	a(1, 1, 1) = 7;
	a(0, 0, 2) = 8;
	a(1, 0, 2) = 9;
	a(0, 1, 2) = 10;
	a(1, 1, 2) = 11;
	
	getchar();
	
	
}