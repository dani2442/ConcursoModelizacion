#pragma once
#include "Layer.h"
#include "FullyConnected.h"
#include "Convolution.h"
#include "MaxPooling.h"
#include "AveragePooling.h"

#include "Activation.h"
#include "Sigmoid.h"
#include "ReLU.h"

#include <vector>


class NeuralNet
{
private:
	std::vector<Layer*> layers;


	void add(Layer* layer) {
		layers.push_back(layer);
	}
};

