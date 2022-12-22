#include "MLP.hpp"

int main()
{
	s21::MLP mlp;

	auto start = std::chrono::steady_clock::now();
	mlp.fileToInput(FILENAME);
	mlp.initMatrix(4);
	mlp.weightsFromFile();
//	mlp.crossValid();
//	mlp.weightsToFile();
	mlp.test();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
}

// 1500