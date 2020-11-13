#pragma once
#include "Layer.h"
#include <string>
#include <unsupported/Eigen/CXX11/Tensor>

template<typename Activation>
class AveragePooling: public Layer
{
private:
	ModeLayer mode;
	u_int s_x, s_y, s_z, ch;

	Eigen::Tensor<Scalar,4> Z;
	Eigen::Tensor<Scalar, 4> A;

	Eigen::Tensor<u_int, 4> Loc;

	Eigen::Tensor<Scalar, 4> d_in;

public:
	AveragePooling(u_int size_x, u_int size_y, u_int size_z, u_int channels, u_int stride,std::string padding="valid") :
		Layer(), s_x(size_x),s_y(size_y),s_z(size_z),ch(channels)
	{
		switch (padding)
		{
		case("valid"):
			mode = ModeLayer::Valid; break;
		case("same"):
			mode = ModeLayer::Same; break;
		case("full"):
			mode = ModeLayer::Full; break;
		default:
			throw "Mode Layer not valid";
		}
	}


	virtual void init(const Scalar& mu, const Scalar& sigma, RNG& rng) {

	}
	virtual void forward(const Matrix& previous_layer) {}
	virtual void backward(const Matrix& previous_layer, const Matrix& next_layer) {}
	virtual const Matrix& get_backward_data() const {}
	virtual void update(Optimizer& opt) {}
};
