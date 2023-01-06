#ifndef CPP7_MLP_MLP_HPP
#define CPP7_MLP_MLP_HPP

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "MLP.hpp"

#define FILENAME "/Users/ddurrand/Desktop/MLP/datasets/emnist-letters-train.csv"
#define WEIGHTSFILE "weights2.w"

namespace s21 {

class Matrix : public MLP{
 private:
  std::vector<std::vector<double>> _input;

  int _layersNb;
  std::vector<std::vector<double>> _neurons;
  std::vector<std::vector<std::vector<double>>> _weights;
  std::vector<std::vector<double>> _localGradArray;

 public:
  void fileToInput(const std::string &fileName);
  void initModel(int _layersNb) override;
  void genWeights() override;
  void fillInputNeurons(int inputIndex);

  void backpropagation(std::vector<double> expected);
  void predict();
//  void changeWeights();

  void crossValid() override;
  void changeWeights(int l, int n, double localGrad);

  void exportWeightsToFile() override;
  void importWeightsFromFile() override;

  void test();
  void epoch();
  void printOutNeurons();
};
}  // namespace s21

#endif  // CPP7_MLP_MLP_HPP
