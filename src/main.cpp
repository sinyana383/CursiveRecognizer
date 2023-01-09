#include "Graph/graph.h"
#include "Matrix/Matrix.hpp"

void testGraph();
void testMatrix();

int main(void)
{
//  testGraph();
  testMatrix();
  return 0;
}

void testGraph()
{
  auto start = std::chrono::steady_clock::now();
  std::vector<double> report;
  s21::GraphPerceptron graph(2);


//  graph.InitGraphPerceptron();
//  graph.GenerateWeightNeuron();
//
//  graph.LoadValuesTrain("/Users/ddurrand/Desktop/Den1s/emnist-letters-train.csv");
//  graph.EpochTrain(1, &report);

//  graph.CrossValidation("/Users/ddurrand/Desktop/Den1s/emnist-letters-train.csv", 2);
//  graph.SaveWeights("weights.w");

  graph.LoadWeights("weights.w");
  char a[200] = "/Users/ddurrand/Desktop/Den1s/emnist-letters-test.csv";
  graph.Testing(a);

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
}

void testMatrix()
{
  auto start = std::chrono::steady_clock::now();
  s21::Matrix matrix;

  matrix.getDataFromFile("/Users/ddurrand/Desktop/Den1s/emnist-letters-train.csv");
  matrix.initModel(4);
  matrix.epoch();
//  matrix.exportWeightsToFile("weights.w");

  matrix.getDataFromFile("/Users/ddurrand/Desktop/Den1s/emnist-letters-test.csv");
//  matrix.initModel(4);
//  matrix.importWeightsFromFile("weights.w");
  matrix.test();
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
}