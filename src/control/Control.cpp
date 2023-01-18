//
// Created by 1 on 13.01.2023.
//

#include "Control.hpp"

namespace s21 {

Control::Control() {
  _matrix.initModel(_hiddenLayeresNb + 2);
}
void Control::saveWeights(const std::string &fileName) {
  if (_mlpType == MATRIX)
    _matrix.exportWeightsToFile(fileName);
  else
    _graph.SaveWeights(fileName);
}
void Control::loadWeights(const std::string &fileName) {
  if (_mlpType == MATRIX)
    _matrix.importWeightsFromFile(fileName);
  else
    _graph.LoadWeights(fileName);
}

void Control::crossValidation(int k) { // не работает
  if (_mlpType == MATRIX) {
    _matrix.getDataFromFile(_trainFile);
    _matrix.genWeights();
    _matrix.crossValid(k);
  } else {
    _graph.GenerateWeightNeuron();
    _graph.CrossValidation(_trainFile, k);
  }
}

std::vector<int> Control::predict(std::vector<double> pixel) { // вернет номер буквы, скорее всего
  std::vector<std::vector<double>> newInput(1, pixel);
  if (_mlpType == MATRIX) {
    _matrix.setInput(newInput);
    _matrix.importWeightsFromFile(_weightsFile);
	return _matrix.predictLetter();
  } else {
    _graph.setInput(newInput);
    _graph.LoadWeights(_weightsFile);
    return _graph.Predict(_trainFile); // поменять функцию
  }
}

void Control::train(int epochNb, std::vector<double> &errors) {
  if (_mlpType == MATRIX) {
    _matrix.getDataFromFile(_trainFile);
    _matrix.genWeights();
    _matrix.epoch(epochNb, errors);
  } else {
    _graph.LoadValuesTrain(_trainFile);
    _graph.GenerateWeightNeuron();
    _graph.EpochTrain(epochNb, &errors);
  }
}
void Control::test(double part) {
  if (_mlpType == MATRIX) {
    _matrix.getDataFromFile(_testFile);
    _matrix.test(part);
  } else {
    _graph.LoadValuesTest(_testFile);
    _graph.Test(part);
  }
}

void Control::setHiddenLayerNb(int nb) {
  _hiddenLayeresNb = nb;
  if (_mlpType == GRAPH)
    _graph.ResizePerceptron(nb);
  else
    _matrix.initModel(_hiddenLayeresNb + 2);
}

void Control::setMlpType(bool type) {
  _mlpType = type;
  if (_mlpType == GRAPH)
    _graph.ResizePerceptron(_hiddenLayeresNb);
  else
    _matrix.initModel(_hiddenLayeresNb + 2);
}

}



