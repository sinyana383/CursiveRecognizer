#include "MLP.hpp"

void s21::MLP::getDataFromFile(const std::string &fileName) {
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
  }
}
void s21::MLP::exitError(const std::string &massage) {
  std::cout << massage << std::endl;
  exit(EXIT_FAILURE);
}

