#pragma once
#include "Layer.h"
#include "FullyConnected.h"
#include "Convolution.h"
#include "MaxPooling.h"
#include "AveragePooling.h"

#include "Activation.h"
#include "Sigmoid.h"
#include "ReLU.h"

#include "Output.h"
#include "RegressionMSE.h"


#include "Optimizer.h"
#include "SGD.h"

#include <vector>

class NeuralNet
{
private:
	std::vector<Layer*> layers;
	Output *output, *default_output;
	Optimizer *optimizer, *default_optimizer;

public:
	NeuralNet(): output(NULL),optimizer(NULL) {
		default_output = new RegressionMSE();
		default_optimizer = new SGD();
	}
	~NeuralNet() { 
		delete output, default_output;
		delete optimizer, default_optimizer; 
		for (int i = 0; i < layers.size(); i++) delete layers[i];
	}

	void init(const Scalar& mu=Scalar(0),const Scalar& sigma=Scalar(0.01),int seed=1){}

	void fit(const Matrix& x, const Matrix& y, int batch_size, int epoch, int seed = 1) {}

	void predict(const Matrix& x){}

	void setOutput(Output* output) { this->output = output;	}

	void setOptimizer(Optimizer* optimizer) { this->optimizer = optimizer; }

	void add(Layer* layer) { layers.push_back(layer); }


};