#include "MLP.hpp"

int main()
{
	s21::MLP mlp;

	auto start = std::chrono::steady_clock::now();
	mlp.fileToInput("/Users/ddurrand/Desktop/MLP/CPP7_MLP/datasets/file1");
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << std::chrono::duration <double> (diff).count() << " sec" << std::endl;
}

/*
 * auto start = chrono::steady_clock::now();

//  Insert the code that will be timed

auto end = chrono::steady_clock::now();

// Store the time difference between start and end
auto diff = end - start;
 * */