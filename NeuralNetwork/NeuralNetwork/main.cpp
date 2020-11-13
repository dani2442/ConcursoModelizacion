#include "Config.h"
#include "NeuralNet.h"
#include "Layer.h"
#include <iostream>

#include <Eigen/Core>
#include <chrono> 
#include <ctime>
#include <unsupported/Eigen/CXX11/Tensor>




/*
- Network
	- Layer
		- Fully Connected
		- Convolution
		- Average Pooling
		- Max Pooling
	- Output
		- RMS Regression (root mean square)
	- Activation
		- Identity
		- ReLU
		- Softmax
		- Sigmoid
		- Tanh
	- Optimizer
		- SGD
	- Random

*/

 
int main() {
	NeuralNet net;
	Layer* l1 = new Convolution<ReLU>(12, 3, 4, 5, 6, "valid");
	Layer* l2 = new FullyConnected<Sigmoid>(12, 4);
	

	net.add(l1);
	net.add(l2);



	Eigen::Tensor<int,3>a(2, 2, 3);
	a(0, 0, 0) = 000;
	a(1, 0, 0) = 100;
	a(0, 1, 0) = 010;
	a(1, 1, 0) = 110;
	a(0, 0, 1) = 001;
	a(1, 0, 1) = 101;
	a(0, 1, 1) = 011;
	a(1, 1, 1) = 111;
	a(0, 0, 2) = 002;
	a(1, 0, 2) = 102;
	a(0, 1, 2) = 012;
	a(1, 1, 2) = 112;
	//Eigen::array<int, 3> start = { 0,0,0 }, end = { 1,1,0 };
	//std::cout << a.slice(start, end);
	std::cout << Eigen::Map < Eigen::Matrix<int, 2, 6>>(a.data());
	getchar();
	
	
}