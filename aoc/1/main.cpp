#include "IO.h"
#include "Measurements.h"
#include <iostream>

int main()
{
	std::vector<std::string> lines = IO::ReadLines("input.txt");
	std::vector<int> readings;
	for (const std::string& line : lines)
		readings.push_back(stoi(line));

	//Part 1
	std::cout << "The number of times the depth reading increased between measurements was: " << ComputeTotalIncreases(readings, 1) << std::endl;

	//Part 2
	std::cout << "The number of times the depth reading increased between measurements was: " << ComputeTotalIncreases(readings, 3) << std::endl;
}