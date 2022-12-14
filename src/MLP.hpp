#ifndef CPP7_MLP_MLP_HPP
#define CPP7_MLP_MLP_HPP

#include <iostream>
#include <fstream>

#include <vector>
#include <string>

#include <cmath>
#include <cstdlib>
#include <ctime>

namespace s21
{
	constexpr int inNeuronsNb = 784;
	constexpr int outNeuronsNb = 26;
	constexpr int hiddenNeuronsNb = 100;

	class MLP
	{
	private:
		std::vector<std::vector<double>> _input;

		int 											_layersNb;
		std::vector<std::vector<double>> 				_sigmoidRes;
		std::vector<std::vector<std::vector<double>>> 	_weights;

	public:
		void 	initMatrix(int _layersNb);
		void 	fileToInput(const std::string &fileName);
		void	exitError(const std::string &massage);

		double	sigmoid(double a) { return 2/(1 + exp(-a)) - 1; }
		double	df_sig(double a){ return 0.5*(1 + a)*(1 - a); }
		void 	predict();
		void	backpropagation();

		void test();
	};
}

#endif //CPP7_MLP_MLP_HPP
