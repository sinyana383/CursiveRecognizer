#include <algorithm>
#include "Matrix.hpp"

void s21::Matrix::initModel(int layersNb) {
  _layersNb = layersNb;
  _neurons.resize(_layersNb);
  _weights.resize(_layersNb);
  _localGradArray.resize(_layersNb);
  _neurons[0].resize(inNeuronsNb);
  _weights[0].resize(0);
  _localGradArray[0].resize(0);

  for (int i = 1; i < _layersNb - 1; ++i) {
    _neurons[i].resize(hiddenNeuronsNb);
    _weights[i].resize(hiddenNeuronsNb);
    _localGradArray[i].resize(hiddenNeuronsNb);
    for (int j = 0; j < hiddenNeuronsNb; ++j) {
      if (i == 1)
	  {
        _weights[i][j].resize(inNeuronsNb);
	  }
      else
	  {
        _weights[i][j].resize(hiddenNeuronsNb);
	  }
    }
  }

  _neurons[_layersNb - 1].resize(outNeuronsNb);
  _weights[_layersNb - 1].resize(outNeuronsNb);
  _localGradArray[_layersNb - 1].resize(outNeuronsNb);
  for (int j = 0; j < outNeuronsNb; ++j)
  {
    _weights[_layersNb - 1][j].resize(hiddenNeuronsNb);
  }

  genWeights();
}
void s21::Matrix::genWeights() {
  srand(time(nullptr));
  for (int i = 1; i < _weights.size(); ++i) {
    for (int j = 0; j < _weights[i].size(); ++j) {
      for (int w = 0; w < _weights[i][j].size(); ++w)
        _weights[i][j][w] = (std::rand() % 2000 - 1000) * 0.001;
    }
  }
}
void s21::Matrix::fillInputNeurons(int inputIndex) {
  if (inputIndex >= _input.size()) exitError("out of input in file");
  for (int i = 0; i < inNeuronsNb; ++i)
    _neurons[0][i] = _input[inputIndex][i + 1] / 255;
}

void s21::Matrix::predict() {
  double product = 0;

  for (int i = 1; i < _layersNb; ++i) {
    for (int j = 0; j < _weights[i].size(); ++j) {
      product = 0;
      for (int w = 0; w < _weights[i][j].size(); ++w)
        product += _neurons[i - 1][w] * _weights[i][j][w];
      _neurons[i][j] = sigmoid(product);
    }
  }
}

void s21::Matrix::backpropagation(std::vector<double> expected) {
  for (int l = _layersNb - 1; l > 0; --l) {
    for (int n = 0; n < _neurons[l].size(); ++n) {
      double err = 0;
      if (l == _layersNb - 1)
        err = _neurons[l][n] - expected[n];
      else {
        for (int i = 0; i < _localGradArray[l + 1].size(); ++i)
          err += _localGradArray[l + 1][i] * _weights[l + 1][i][n];
      }
      double localGrad = err * df_sigmoid(_neurons[l][n]);
      _localGradArray[l][n] = localGrad;
	  if (std::abs(localGrad) - 0.00001 > 0)
	  {
		for (int w = 0; w < _weights[l][n].size(); ++w)
		  _weights[l][n][w] -= _neurons[l - 1][w] * localGrad * LerningStep;
	  }
    }
  }
}

void s21::Matrix::crossValid() {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < _input.size(); ++j) {
	  if (j == i * (_input.size() / k))
	  {
		j += _input.size() / k;
		if (j >= _input.size())
		  break;
	  }
      train(j);
    }
	int right = 0;
	for (int j = i * (_input.size() / k); j <  i * (_input.size() / k) + (_input.size() / k); ++j)
	{
	  fillInputNeurons(j);
	  predict();
	  int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin(); // !!!
	  if (indexMax + 1 == _input[j][0])
		++right;
	}
	std::cout << right << " / " << _input.size() / k << std::endl;
  }
}


void s21::Matrix::epoch()
{
  int inputIndex = 0;
  _rightPredicts = 0;
  for (int i = 0; i < _input.size(); ++i) {
    fillInputNeurons(inputIndex);
    std::vector<double> expected(outNeuronsNb, 0);
    expected[static_cast<int>(_input[inputIndex][0]) - 1] = 1;
    ++inputIndex;
    predict();
    backpropagation(expected);
    int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin();
    if (indexMax + 1 == _input[i][0])
      ++_rightPredicts;
  }
  std::cout << _rightPredicts << " / " << _input.size() << std::endl;
}

void s21::Matrix::test()
{
  int inputIndex = 0;
  _rightPredicts = 0;
  for (int i = 0; i < _input.size(); ++i) {
	fillInputNeurons(inputIndex);
	++inputIndex;
	predict();
	int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin();
	if (indexMax + 1 == _input[i][0])
	  ++_rightPredicts;
  }
  std::cout << _rightPredicts << " / " << _input.size() << std::endl;
}
void s21::Matrix::train(int inputIndex) {
  std::vector<double> expected(outNeuronsNb, 0); // запихнуть в train
  expected[static_cast<int>(_input[inputIndex][0]) - 1] = 1;
  fillInputNeurons(inputIndex);
  predict();
  backpropagation(expected);
}

void s21::Matrix::exportWeightsToFile(const std::string &fileName) {
  std::ofstream file;
  file.open("weights.w", std::ios::out | std::ios::trunc);
  if (!file.bad() && file.is_open()) {
	for (int l = 1; l < _weights.size(); ++l)
	{
	  for (int n = 0; n < _weights[l].size(); ++n)
	  {
		for (int w = 0; w < _weights[l][n].size(); ++w)
		{
		  file << _weights[l][n][w];
		  if (w < _weights[l][n].size() - 1)
			file << ",";
		}
		file << std::endl;
	  }
	}
  }
  else
	exitError("couldn't creat weights.w file");
  file.close();
}
void s21::Matrix::importWeightsFromFile(std::string const &fileName) {
  std::ifstream fin(fileName, std::ios::in);
  if (!fin.bad() && fin.is_open()) {
	std::vector<double> numbers;
	std::string line;
	int l = 1, n = 0, w;
	while (std::getline(fin, line)) {
	  char *pStart = &(line[0]);
	  char *pEnd;

	  w = 0;
	  do {
		_weights[l][n][w] = std::strtod(pStart, &pEnd);
		++w;
		pStart = pEnd + 1;
	  } while (*pEnd);

	  if (w != _weights[l][n].size())
		exitError("wrong weights number in weights.w");
	  n++;
	  if (n == _weights[l].size())
	  {
		n = 0;
		++l;
	  }
	  if (l > _weights.size())
		exitError("wrong layer number in weights.w");
	}
	if (l != _weights.size())
	  exitError("wrong layer number in weights.w");
  }
  else
	exitError("couldn't open weights.w file");
}

