#include "MLP.hpp"

void s21::MLP::initMatrix()
{

}
void	s21::MLP::exitError(const std::string &massage)
{
	std::cout << massage << std::endl;
	exit(EXIT_FAILURE);
}
void s21::MLP::fileToInput(const std::string &fileName)
{
	for (auto & i : _input)
		i.clear();
	_input.clear();

	static std::ifstream	fin(fileName, std::ios::in);
	if (!fin.bad())
	{
		std::vector<double>	numbers;
		std::string 		line;
		while (fin >> line)
		{
			numbers.reserve(inNeuronsNb);	// поч не экономит время?

			char	*pStart = &(line[0]);
			char	*pEnd;
			do{
				numbers.push_back(std::strtod(pStart, &pEnd));
				pStart = pEnd + 1;
			}while (*pEnd);
			if (numbers.size() != 785)
				exitError("size is not 784 pixels");
			_input.push_back(numbers);
			numbers.clear();
		}
	}
	else
		exitError("can't open file");
}

void s21::MLP::predict()
{

}


/*
 void dot_product_on_neurons_with_sig1(double neurons[], int n_size,
				 const double input[], double (*weight)[3], int i_size)
{
	for (int i = 0; i < n_size; ++i)
	{
		double product = 0;
		for (int j = 0; j < i_size; ++j)
			product += input[j] * weight[i][j];
		neurons[i] = sigmoid(product);
	}
}
 */