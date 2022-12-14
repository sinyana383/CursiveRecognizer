#include "MLP.hpp"

void s21::MLP::initMatrix(int layersNb)
{
    _layersNb = layersNb;
    _sigmoidRes.resize(_layersNb - 1);
    _weights.resize(_layersNb - 1);

    // set size to _weights and _sigmoidRes
    for (int i = 0; i < _layersNb - 2; ++i)
    {
        _sigmoidRes[i].resize(hiddenNeuronsNb);
        _weights[i].resize(hiddenNeuronsNb);
        for (int j = 0; j < hiddenNeuronsNb; ++j)
        {
            if (i == 0)
                _weights[i][j].resize(inNeuronsNb);
            else
                _weights[i][j].resize(hiddenNeuronsNb);
        }
    }

    // init weights
    srand(time(nullptr));
    for (int i = 0; i < _weights.size(); ++i)
    {
        for (int j = 0; j < _weights[i].size(); ++j)
        {
            for (int w = 0; w < _weights[i][j].size(); ++w)
                _weights[i][j][w] = rand() % 1000 * 0.001;
        }
    }

    _sigmoidRes[_layersNb - 2].resize(outNeuronsNb);
    _weights[_layersNb - 2].resize()    // че делать
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