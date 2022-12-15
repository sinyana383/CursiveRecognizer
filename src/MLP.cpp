#include "MLP.hpp"

void	s21::MLP::fileToInput(const std::string &fileName)
{
	for (auto & i : _input)
		i.clear();
	_input.clear();

	std::ifstream	fin(fileName, std::ios::in);
	if (!fin.bad() && fin.is_open())
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
		exitError("couldn't open file");
}
void	s21::MLP::initMatrix(int layersNb)
{
	// set size to _weights and _sigmoidRes
	_layersNb = layersNb;
	_neurons.resize(_layersNb);
	_weights.resize(_layersNb);
	_localGradArray.resize(_layersNb);
	_neurons[0].resize(inNeuronsNb);
	_weights[0].resize(0);
	_localGradArray[0].resize(0);

	for (int i = 1; i < _layersNb - 1; ++i)
	{
		_neurons[i].resize(hiddenNeuronsNb);
		_weights[i].resize(hiddenNeuronsNb);
		_localGradArray[i].resize(hiddenNeuronsNb);
		for (int j = 0; j < hiddenNeuronsNb; ++j)
		{
			if (i == 1)
				_weights[i][j].resize(inNeuronsNb);
			else
				_weights[i][j].resize(hiddenNeuronsNb);
		}
	}

	_neurons[_layersNb - 1].resize(outNeuronsNb);
	_weights[_layersNb - 1].resize(outNeuronsNb);
	_localGradArray[_layersNb - 1].resize(outNeuronsNb);
	for (int j = 0; j < outNeuronsNb; ++j)
		_weights[_layersNb - 1][j].resize(hiddenNeuronsNb);

	// init weights and neurons
	genWeights();
	fillInputNeurons();
}
void	s21::MLP::genWeights()
{
	srand(time(nullptr));
	for (int i = 1; i < _weights.size(); ++i)
	{
		for (int j = 0; j < _weights[i].size(); ++j)
		{
			for (int w = 0; w < _weights[i][j].size(); ++w)
				_weights[i][j][w] = ( std::rand() % 2000 - 1000) * 0.001;
		}
	}
}
void	s21::MLP::fillInputNeurons()
{
	++_inputIndex;
	for (int i = 0; i < inNeuronsNb; ++i)
		_neurons[0][i] = _input[_inputIndex][i + 1] / 255;
	if (_inputIndex >= _input.size())
		exitError("out of input in file");
}
void	s21::MLP::exitError(const std::string &massage)
{
	std::cout << massage << std::endl;
	exit(EXIT_FAILURE);
}

void	s21::MLP::predict()
{
	double product = 0;

	for (int i = 1; i < _layersNb; ++i)
	{
		for (int j = 0; j < _neurons[i].size(); ++j)
		{
			product = 0;
			for (int w = 0; w < _weights[i][j].size(); ++w)
				product += _neurons[i - 1][w] * _weights[i][j][w];
			_neurons[i][j] = sigmoid(product);
		}
	}
}
void	s21::MLP::backpropagation()
{
	std::vector<double> expected(outNeuronsNb, 0);
	expected[static_cast<int>(_input[_inputIndex][0])] = 1;

	for (int l = _layersNb - 1; l > 0; --l)
	{
		for (int n = 0; n < outNeuronsNb; ++n)
		{
			double err = 0;
			if (l == _layersNb - 1)
				err = _neurons[l][n] - expected[n];
			else
			{
				// прошлого лок градиента и привязанных весов к нейрону i
				for (int i = 0; i < _localGradArray[l + 1].size(); ++i)
					err += _localGradArray[l + 1][n] * _weights[l + 1][i][n];
			}
			double localGrad = err * df_sigmoid(_neurons[l][n]);
			_localGradArray[l][n] = localGrad;
			changeWeights(l, n, localGrad);
		}
	}
}
void	s21::MLP::changeWeights(int l, int n, double localGrad)
{
	for (int w = 0; w < _weights[l][n].size(); ++w)
		_weights[l][n][w] -= _neurons[l - 1][w] * localGrad * LerningStep;
}