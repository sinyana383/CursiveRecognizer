//
// Created by 1 on 13.01.2023.
//

#include "Control.hpp"
Control::Control() {
  _matrix.initModel(_hiddenLayeresNb + 2);
}
void Control::saveWeights(const std::string &fileName) {
  if (_mlpType == MATRIX) // дописать контроллер
    _matrix.exportWeightsToFile(fileName);
  else
    _graph.SaveWeights(fileName);
}
void Control::loadWeights(const std::string &fileName) {
  if (_mlpType == MATRIX) // дописать контроллер
    _matrix.importWeightsFromFile(fileName);
  else
    _graph.LoadWeights(fileName);
}

void Control::crossValidation(int k) {
  if (_mlpType == MATRIX)
  {
    _matrix.getDataFromFile(_trainFile);
    _matrix.genWeights();
    _matrix.crossValid(k);
  }
  else
  {
    _graph.GenerateWeightNeuron();
    _graph.CrossValidation(_trainFile, k);
  }
}
void Control::train(int epochNb, std::vector<double> &errors) {
  if (_mlpType == MATRIX)
  {
    _matrix.getDataFromFile(_trainFile);
    _matrix.genWeights();
    _matrix.epoch(epochNb, errors);
  }
  else
  {
    _graph.LoadValuesTrain(_trainFile);
    _graph.GenerateWeightNeuron();
    _graph.EpochTrain(epochNb, &errors);
  }
}
void Control::test(double part) {
  if (_mlpType == MATRIX)
  {
    _matrix.getDataFromFile(_testFile);
    _matrix.test(part);
  }
  else
  {
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



