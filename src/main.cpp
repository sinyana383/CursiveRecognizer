#include "MLP.hpp"

int main()
{
	s21::MLP mlp;

	auto start = std::chrono::steady_clock::now();
	mlp.fileToInput("/Users/ddurrand/Desktop/MLP_CPP 2/datasets/file1");
	mlp.initMatrix(5);
	mlp.test();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
}