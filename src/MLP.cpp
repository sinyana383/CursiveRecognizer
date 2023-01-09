#include "MLP.hpp"

namespace s21 {

void MLP::getDataFromFile(std::string const &fileName) {
  ClearInput();

  std::ifstream fin(fileName, std::ios::in);
  if (!fin.bad() && fin.is_open()) {
	std::vector<double> numbers;
	std::string line;
	while (fin >> line) {
//      numbers.reserve(inNeuronsNb);
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

void MLP::ClearInput() {
  for (size_t j = 0; j < _input.size(); j++) {
	_input[j].clear();
  }
  _input.clear();
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
void MLP::exitError(const std::string &massage) {
  std::cout << massage << std::endl;
  exit(EXIT_FAILURE);
}
}