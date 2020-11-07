#pragma once
#include "Layer.h"

template<typename Activation>
class FullyConnected: public Layer
{
	Matrix W,d_W;
	Vector B,d_B;
	Matrix A, Z, D_in;

	FullyConnected(const int in_size,const int out_size):Layer(in_size,out_size){}

	void init(const Scalar& mu, const Scalar& sigma, RNG& rng) {
		W.resize(in_size, out_size);
		B.resize(out_size);
		d_W.resize(in_size, out_size);
		d_B.resize(out_size);

		rng.set_normal_random(W.data(), W.size(), mu, sigma); // Set normal random initizalization for W and B
		rng.set_normal_random(B.data(), B.size(), mu, sigma);
	}
	void forward(const Matrix& previous_layer){
		const int s_batch=previous_layer.cols(); // Batch size

		// Z=W^T*X+B
		Z.resize(out_size, s_batch);
		Z.noalias() = W.transpose() * previous_layer;
		Z.colwise() += B;

		// A=f(Z)
		A.resize(out_size, s_batch);
		Activation::activate(Z, A);
	}

	void backward(const Matrix& previous_layer, const Matrix& next_layer) {
		const int s_batch = previous_layer.cols();
		Activation::aply_jacobian(Z, A, next_layer, Z);
		d_W.noalias() = previous_layer * Z.transpose() / s_batch;
		d_B.noalias() = Z.rowwise().mean();

		d_in.resize(in_size, s_batch);
		d_in.noalias() = W * Z;
	}

	const Matrix& get_backward_data() const { return d_in; }

	void update(Optimizer& opt) {
		ConstAlignedMapVec dw(d_W.data(), d_W.size());
        ConstAlignedMapVec db(d_B.data(), d_B.size());
        AlignedMapVec      w(W.data(), W.size());
        AlignedMapVec      b(B.data(), B.size());

        opt.update(dw, w);
        opt.update(db, b);
	}
};

