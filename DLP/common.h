#ifndef COMMON_H
#define COMMON_H

#include <atomic>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <vector>

namespace s21 {
constexpr double learning_rate = 0.25;
constexpr double neuron_out = 26;
constexpr double neuron_hidden = 40;
constexpr double neuron_in = 784;
constexpr int full_sample = 5;

class MLP {
 public:
  // Common //
  void getDataFromFile(std::string const &fileName);
  virtual void genWeights() = 0;
  void CrossValidation(int k_validation);

  static void exitError(const std::string &massage);
  static double sigmoid(double a) { return 1.0 / (1.0 + std::exp(-a)); }
  static double df_sigmoid(double a) { return a * (1.0 - a); }

  // Calc result //
  std::vector<double> CalculateMetrics();
  virtual double CalculatePercent(int k_group) = 0;
  double CalculatePercentTrain() {
    double k =
        ((double)_rightPredicts / (double)vector_vectorovi4.size());
    return k;
  }

  // Getters
  std::vector<std::vector<double>> GetVector() { return _input; }
  int GetSize() { return vector_vectorovi4.size(); }

  // Run
  virtual void train(int inputIndex) = 0;
  virtual void test(int inputIndex) = 0;

  // Stop
  void SetExitTrain(bool var) { exit_train_ = var; }
  void SetStopTrainOrTest(bool var) { stop_train_or_test_ = var; }

 protected:
  bool exit_train_ = false;

  int _rightPredicts = 0;
  int _expectedLetter = 0;
  int size_letter_for_epoch = 0;

  std::vector<std::vector<double>> vector_vectorovi4;
  std::vector<std::vector<double>> vector_for_test;
  std::vector<std::vector<double>> _input;

  double time = 0;					//?

  int crossvalidation = 0;			//?
  int _k = 0;
  int anti_k = 0;						//?

  int current_percent = 0;			// ?
  int vec_size = 0;					// ?
  std::mutex m_mutex;				// неужели запускать в разных потоках две модели одновременно?
  bool stop_train_or_test_ = false;

  //Metrics //
  double accuracy = 0;
  double f_measure = 0;
  double precision = 0;
  double recall = 0;
  std::vector<double> metrics{};

  int true_positive = 0;
  int true_negative = 0;
  int false_positive = 0;
  int false_negative = 0;
};

}
#endif  
