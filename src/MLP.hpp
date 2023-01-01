#ifndef CPP7_MLP_MLP_HPP
#define CPP7_MLP_MLP_HPP

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define FILENAME "C:\\Users\\1\\Desktop\\MLP\\datasets\\emnist-letters-test.csv"
#define WEIGHTSFILE "weights2.w"

namespace s21 {
constexpr int inNeuronsNb = 784;
constexpr int outNeuronsNb = 26;
constexpr int hiddenNeuronsNb = 35;
constexpr double LerningStep = 0.25;
constexpr int k = 4;

class MLP {
 private:
  std::vector<std::vector<double>> _input;

  int _layersNb;
  std::vector<std::vector<double>> _neurons;
  std::vector<std::vector<std::vector<double>>> _weights;
  std::vector<std::vector<double>> _localGradArray;

 public:
  void fileToInput(const std::string &fileName);
  void initMatrix(int _layersNb);
  void genWeights();
  void fillInputNeurons(int inputIndex);
  void exitError(const std::string &massage);

  static double sigmoid(double a) { return 1.0 / (1.0 + std::exp(-a)); }
  static double df_sigmoid(double a) { return a * (1.0 - a); }
  void backpropagation(std::vector<double> expected);
  void predict();
//  void changeWeights();

  void crossValid();
  void changeWeights(int l, int n, double localGrad);

  void weightsToFile();
  void weightsFromFile();

  void test();
  void epoch();
  void printOutNeurons();
};
}  // namespace s21

#endif  // CPP7_MLP_MLP_HPP
