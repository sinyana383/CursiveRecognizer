#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

double sigmoid(double a) { return 2 / (1 + exp(-a)) - 1; }

double df_sig(double a) { return 0.5 * (1 + a) * (1 - a); }

void dot_product_on_neurons_with_sig1(double neurons[], int n_size,
                                      const double input[], double (*weight)[3],
                                      int i_size) {
  for (int i = 0; i < n_size; ++i) {
    double product = 0;
    for (int j = 0; j < i_size; ++j) product += input[j] * weight[i][j];
    neurons[i] = sigmoid(product);
  }
}

void dot_product_on_neurons_with_sig2(double neurons[], int n_size,
                                      const double input[], double (*weight)[2],
                                      int i_size) {
  for (int i = 0; i < n_size; ++i) {
    double product = 0;
    for (int j = 0; j < i_size; ++j) product += input[j] * weight[i][j];
    neurons[i] = sigmoid(product);
  }
}

void predict(double neurons[], double output[], double input[],
             double (*weight1)[3], double (*weight2)[2]) {
  dot_product_on_neurons_with_sig1(neurons, 2, input, weight1, 3);
  dot_product_on_neurons_with_sig2(output, 3, neurons, weight2, 2);
}

void learn(double (*epoch)[3], double neurons[], double output[],
           double (*weight1)[3], double (*weight2)[2]) {
  double step = 0.5;
  int iters = 1000;

  double err;
  double loc_grad;
  double loc_grad2[2];

  std::srand(std::time(nullptr));
  for (int i = 0; i < iters; ++i) {
    int ep_index = std::rand() % 3;
    predict(neurons, output, epoch[ep_index], weight1, weight2);

    for (int j = 0; j < 3; ++j) {
      err = output[j] - epoch[ep_index][j];
      loc_grad = err * df_sig(output[j]);
      weight2[j][0] -= loc_grad * neurons[0] * step;
      weight2[j][1] -= loc_grad * neurons[1] * step;

      loc_grad2[0] = weight2[j][0] * loc_grad * df_sig(neurons[0]);
      loc_grad2[1] = weight2[j][1] * loc_grad * df_sig(neurons[1]);

      for (int k = 0; k < 3; ++k)
        weight1[0][k] -= epoch[ep_index][k] * loc_grad2[0] * step;
      for (int k = 0; k < 3; ++k)
        weight1[1][k] -= epoch[ep_index][k] * loc_grad2[1] * step;
    }
  }
}

std::vector<int> input(785, 0);

// int main()
//{
//	double epoch[3][3] = {
//			{1, -1, -1},
//			{-1, 1, -1},
//			{-1, -1, 1}
//	};
//
//	double test[8][3] =  {{-1, -1, -1},	// no
//						  {-1, -1, 1}, 	// g
//						  {-1, 1, -1}, 	// y
//						  {-1, 1, 1},  	// y g
//						  {1, -1, -1}, 	// r
//						  {1, -1, 1},  	// r g
//						  {1, 1, -1},  	// r y
//						  {1, 1, 1}};  	// r y g
//
//	double w1[2][3] = {
//			{-0.2, 0.3, -0.4},
//			{0.1, -0.3, -0.4}
//	};
//	double w2[3][2] = {
//			{0.2, 0.3},
//			{0.3, 0.5},
//			{0.3, 0.7}
//	};
//
//	double neurons[2] = {};
//	double output[3] = {};
//
//	learn(epoch, neurons, output, w1, w2);
//
//	for (int i = 0; i < 8; ++i)
//	{
//		predict(neurons, output, test[i], w1, w2);
//		for (int j = 0; j < 3; ++j)
//			std::cout << output[j] << " ";
//		std::cout << std::endl;
//	}
//	return 0;
// }
