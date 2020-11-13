#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Core>
#include <iostream>

// documentation: https://eigen.tuxfamily.org/dox/unsupported/eigen_tensors.html

using namespace Eigen;
int main(){
	//Tensor<float, 3> t_3d;

	//t_3d = Tensor<float, 3>(3, 4, 3);

	//t_3d.resize(2, 3,4);

	//int storage[18] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};  // 2 x 3 x 3 = 128
	//TensorMap<Tensor<int, 3>> t_4d(storage, 2, 3, 3);

	Tensor<float, 3> t_3d(2, 3, 4);
	t_3d(0, 1, 0) = 12.0f;

	// Initialize all elements to random values.
	for (int i = 0; i < 2; ++i) {
	  for (int j = 0; j < 3; ++j) {
		for (int k = 0; k < 4; ++k) {
		  t_3d(i, j, k) = i*100+j*10+k;
		}
	  }
	}

	Tensor<float,3> t_3d2=t_3d*0.3f;
	std::cout << t_3d2(1, 0, 0);
	getchar();
}