#include <chrono>
#include "Matrix.hpp"

int main()
{
	s21::Matrix mlp;

	mlp.fileToInput(FILENAME);
    mlp.initModel(4);
//	mlp.weightsFromFile();
    auto start = std::chrono::steady_clock::now();
	mlp.crossValid();
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
    mlp.exportWeightsToFile();
//	mlp.test();
}

//_weights[i][j][w] = (std::rand() % 2000 - 1000) * 0.001;
