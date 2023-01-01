#include <algorithm>
#include "MLP.hpp"

void s21::MLP::fileToInput(const std::string &fileName) {
  for (auto &i : _input) i.clear();
  _input.clear();

  std::ifstream fin(fileName, std::ios::in);
  if (!fin.bad() && fin.is_open()) {
    std::vector<double> numbers;
    std::string line;
    while (fin >> line) {
//      numbers.reserve(inNeuronsNb);  // поч не экономит время?
      char *pStart = &(line[0]);
      char *pEnd;
      do {
        numbers.push_back(std::strtod(pStart, &pEnd));
        pStart = pEnd + 1;
      } while (*pEnd);
      if (numbers.size() != 785) exitError("size is not 784 pixels");
      _input.push_back(numbers);
      numbers.clear();
    }
  } else
    exitError("couldn't open file");
}
void s21::MLP::initMatrix(int layersNb) {
  // set size to _weights and _sigmoidRes
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

  // init weights and neurons
  genWeights();
  fillInputNeurons(0);
}
void s21::MLP::genWeights() {
  srand(time(nullptr));
  for (int i = 1; i < _weights.size(); ++i) {
    for (int j = 0; j < _weights[i].size(); ++j) {
      for (int w = 0; w < _weights[i][j].size(); ++w)
        _weights[i][j][w] = (std::rand() % 2000 - 1000) * 0.001;
    }
  }
}
void s21::MLP::fillInputNeurons(int inputIndex) {
  if (inputIndex >= _input.size()) exitError("out of input in file");
  for (int i = 0; i < inNeuronsNb; ++i)
    _neurons[0][i] = _input[inputIndex][i + 1] / 255;
}
void s21::MLP::exitError(const std::string &massage) {
  std::cout << massage << std::endl;
  exit(EXIT_FAILURE);
}

void s21::MLP::predict() {
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

void s21::MLP::backpropagation(std::vector<double> expected) {
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
	  	changeWeights(l, n, localGrad);
    }
  }
}

void s21::MLP::changeWeights(int l, int n, double localGrad) {
  for (int w = 0; w < _weights[l][n].size(); ++w)
    _weights[l][n][w] -= _neurons[l - 1][w] * localGrad * LerningStep;
}

void s21::MLP::crossValid() {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < _input.size(); ++j) {
	  if (j == i * (_input.size() / k))
	  {
		j += _input.size() / k;
		if (j >= _input.size())
		  break;
	  }
      std::vector<double> expected(outNeuronsNb, 0);
      expected[static_cast<int>(_input[j][0]) - 1] = 1;
	  fillInputNeurons(j);
	  predict();
	  backpropagation(expected);
    }
//	int right = 0;
//	for (int j = i * (_input.size() / k); j <  i * (_input.size() / k) + (_input.size() / k); ++j)
//	{
//	  fillInputNeurons(j);
//	  predict();
//	  int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin(); // !!!
//	  if (indexMax + 1 == _input[j][0])
//		++right;
////	  printOutNeurons();
//	}
//	std::cout << right << " / " << _input.size() / k << std::endl;
//  }
}

//void s21::MLP::changeWeights() {
//  for (int l = _layersNb - 1; l > 0; --l)
//  {
//	for (int n = 0; n < _weights[l].size(); ++n)
//	{
//	  for (int w = 0; w < _weights[l][n].size(); ++w)
//	  {
//		_weights[l][n][w] -= _crossWeights[l][n][w] / (_input.size() / k);
//		_crossWeights[l][n][w] = 0;
//	  }
//	}
  }
//}

void s21::MLP::epoch()
{
  int inputIndex = 0;
  int right = 0;
  for (int i = 0; i < _input.size(); ++i) {
    fillInputNeurons(inputIndex);
    std::vector<double> expected(outNeuronsNb, 0);
    expected[static_cast<int>(_input[inputIndex][0]) - 1] = 1;
    ++inputIndex;
    predict();
    backpropagation(expected);
    int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin();
    if (indexMax + 1 == _input[i][0])
      ++right;
  }
  std::cout << right << " / " << _input.size() << std::endl;
}

void s21::MLP::test() {
  int inputIndex = 0;
  int right = 0;
  for (int i = 0; i < _input.size(); ++i) {
	fillInputNeurons(inputIndex);
	++inputIndex;
    predict();
	int indexMax = std::max_element(_neurons[_layersNb - 1].begin(), _neurons[_layersNb - 1].end()) - _neurons[_layersNb - 1].begin();
	if (indexMax + 1 == _input[i][0])
	  ++right;
  }
  std::cout << right << " / " << _input.size() << std::endl;
}

void s21::MLP::printOutNeurons() {
  double max = -2;
  int index;
  for (int i = 0; i < _neurons[_layersNb - 1].size(); ++i) {
    if (max - _neurons[_layersNb - 1][i] < 0) {
      max = _neurons[_layersNb - 1][i];
      index = i;
    }
    std::cout << _neurons[_layersNb - 1][i] << std::endl;
  }
  std::cout << index + 1 << " - " << max << std::endl;
}
void s21::MLP::weightsToFile() {
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
void s21::MLP::weightsFromFile() {
  std::ifstream fin("weights.w", std::ios::in);
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
