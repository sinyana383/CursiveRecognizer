#include "graph.h"
#include "layer.h"


int main(void)
{

  auto start = std::chrono::steady_clock::now();
  std::vector<double> report_graph;
    s21::GraphPerceptron graph(4);

	graph.InitGraphPerceptron();

//	graph.LoadWeights("/Users/ddurrand/Desktop/untitled/cmake-build-debug/weights.w");
//	char a[200] = "/Users/ddurrand/Desktop/untitled/emnist-letters-test.csv";
//	graph.Testing(a);

	graph.genWeights();
	graph.LoadValuesTrain("/Users/ddurrand/Desktop/untitled/emnist-letters-train.csv");
//	graph.EpochTrain(1, &report_graph);
	graph.CrossValidation(2);
	graph.SaveWeights("weights.w");

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
    return 0;
}

// 12.9158 sec