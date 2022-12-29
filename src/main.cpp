#include <chrono>
#include "MLP.hpp"

int main()
{
	s21::MLP mlp;

	mlp.fileToInput(FILENAME);
	mlp.initMatrix(4);
//	mlp.weightsFromFile();
    auto start = std::chrono::steady_clock::now();
	mlp.crossValid();
    mlp.crossValid();
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
	mlp.weightsToFile();
//	mlp.test();
}

// 1500