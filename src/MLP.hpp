#ifndef CPP7_MLP_SRC_MLP_HPP_
#define CPP7_MLP_SRC_MLP_HPP_

#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>

namespace s21 {
constexpr int inNeuronsNb = 784;
constexpr int outNeuronsNb = 26;
constexpr int hiddenNeuronsNb = 40;
constexpr double LerningStep = 0.25;
constexpr int k = 2;

class MLP {
 protected:
  std::vector<std::vector<double>> _input;
  int _layersNb;

 public:
  void getDataFromFile(const std::string &fileName);
  virtual void exportWeightsToFile() = 0;
  virtual void importWeightsFromFile() = 0;
  virtual void genWeights() = 0;

  virtual void initModel(int _layersNb) = 0;
  virtual void crossValid() = 0;

  static double sigmoid(double a) { return 1.0 / (1.0 + std::exp(-a)); }
  static double df_sigmoid(double a) { return a * (1.0 - a); }
  static void exitError(const std::string &massage); // заменить exception-ом?
};
}

#endif //CPP7_MLP_SRC_MLP_HPP_
