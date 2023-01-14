//
// Created by 1 on 13.01.2023.
//

#ifndef CPP7_MLP_SRC_CONTROL_HPP_
#define CPP7_MLP_SRC_CONTROL_HPP_

#include <string>
#include <vector>
#include "../Matrix/Matrix.hpp"
#include "../Graph/graph.h"

#define DEFAULTTRAIN "C:\\Users\\1\\Desktop\\MLP\\emnist-letters-train.csv"
#define DEFAULTTEST "C:\\Users\\1\\Desktop\\MLP\\emnist-letters-test.csv"
#define MATRIX false
#define GRAPH true

class Control {
 private:
  s21::Matrix _matrix;
  s21::GraphPerceptron _graph;

  bool _mlpType = MATRIX; // должно отображ у пользователя
  int _hiddenLayeresNb = 2;

  std::vector<double> _errors;
  std::string _trainFile = DEFAULTTRAIN;
  std::string _testFile = DEFAULTTEST;
 public:
  Control();
  void setMlpType(bool type);
  void setHiddenLayerNb(int nb);
  void setTrainFile(std::string const& trainFile) { _trainFile = trainFile; }
  void setTestFile(std::string const& testFile) { _testFile = testFile; }

  void saveWeights(std::string const& fileName);
  void loadWeights(std::string const& fileName);

  void crossValidation(int k);
  void train(int epochNb, std::vector<double> &errors);
  void test(double part); // там какой-то testSample
};

#endif //CPP7_MLP_SRC_CONTROL_HPP_
