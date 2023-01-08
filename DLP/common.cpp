#include "common.h"

namespace s21 {

void MLP::getDataFromFile(std::string const &fileName) {
  for (auto &i : _input) i.clear();
  _input.clear();
  std::ifstream ifs(fileName, std::ios::in);

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
  }
}

void MLP::exitError(const std::string &massage) {
  std::cout << massage << std::endl;
  exit(EXIT_FAILURE);
}

std::vector<double> MLP::CalculateMetrics() {
  metrics.clear();
  accuracy =
	  (double) (true_positive + true_negative) /
		  (double) (true_positive + true_negative + false_positive + false_negative);
  precision = (double) true_positive / (double) (true_positive + false_positive);
  recall = (double) true_positive / (double) (true_positive + false_negative);
  f_measure = 2 * ((precision * recall) / (precision + recall));

  metrics.push_back(accuracy);
  metrics.push_back(precision);
  metrics.push_back(recall);
  metrics.push_back(f_measure);
  return metrics;
}

void MLP::CrossValidation(int k_validation) {
  _k = k_validation;

  for (int i = 0; i < _k; ++i) {
	for (int j = 0; j < _input.size(); ++j) {
	  if (j == i * (_input.size() / _k)) {
		j += _input.size() / _k;
		if (j >= _input.size())
		  break;
	  }
	  train(j);
	}
	int right = 0;
	for (int j = i * (_input.size() / _k); j < i * (_input.size() / _k) + (_input.size() / _k); ++j) {
	  test(j);
	}
	std::cout << CalculatePercent(_k) << std::endl;
	if (i < _k) genWeights();
  }
}
}