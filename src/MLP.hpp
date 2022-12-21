#ifndef CPP7_MLP_MLP_HPP
#define CPP7_MLP_MLP_HPP

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {
constexpr int inNeuronsNb = 784;
constexpr int outNeuronsNb = 26;
constexpr int hiddenNeuronsNb = 100;
constexpr double LerningStep = 0.1;
constexpr int k = 10;

class MLP {
 private:
  int _inputIndex;
  std::vector<std::vector<double>> _input;

  int _layersNb;
  std::vector<std::vector<double>> _neurons;
  std::vector<std::vector<std::vector<double>>> _weights;
  std::vector<std::vector<double>> _localGradArray;

 public:
  void fileToInput(const std::string &fileName);
  void initMatrix(int _layersNb);
  void genWeights();
  void fillInputNeurons();
  void exitError(const std::string &massage);

  static double sigmoid(double a) { return 1 / (1 + exp(-a)); }
  static double df_sigmoid(double a) { return a * (1 - a); }
  void changeWeights(int l, int n, double localGrad);
  void backpropagation();
  void predict();

  void crossValid();
  void test();

  void printOutNeurons();
};
}  // namespace s21

#endif  // CPP7_MLP_MLP_HPP
