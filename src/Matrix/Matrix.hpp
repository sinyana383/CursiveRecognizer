#ifndef CPP7_MLP_MLP_HPP
#define CPP7_MLP_MLP_HPP

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../MLP.hpp"

#define FILENAME "/Users/ddurrand/Desktop/MLP/datasets/emnist-letters-train.csv"
#define WEIGHTSFILE "weights2.w"

namespace s21 {

class Matrix : public MLP{
 private:
  int _layersNb;
  std::vector<std::vector<double>> _neurons;
  std::vector<std::vector<std::vector<double>>> _weights;
  std::vector<std::vector<double>> _localGradArray;

 public:
  void initModel(int _layersNb);
  void genWeights();
  void fillInputNeurons(int inputIndex);

  void backpropagation(std::vector<double> expected);
  void predict();

  void crossValid();

  void exportWeightsToFile(const std::string &fileName);
  void importWeightsFromFile(std::string const &fileName);

  void train(int inputIndex);
  void test();
  void epoch();
};
}  // namespace s21

#endif  // CPP7_MLP_MLP_HPP
