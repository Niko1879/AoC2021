#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "count.h"
#include <limits.h>
#include "IO.h"

int main()
{
	std::vector<std::string> lines = IO::ReadLines("input.txt");
	std::vector<std::string> transposes = Transpose(lines);

	std::stringstream epsilonGammaBuf;
	for (const std::string& t : transposes)
	{
		epsilonGammaBuf << MostCommonBit(t);
	}

	std::string bitsStr = epsilonGammaBuf.str();
	unsigned long gamma = std::stoul(bitsStr, nullptr, 2);
	std::cout << gamma << std::endl;
	unsigned long epsilon = ~gamma & (ULONG_MAX >> (sizeof(unsigned long) * 8 - bitsStr.size()));
	std::cout << epsilon << std::endl;

	std::cout << "The power consumption of the submarine is: " << gamma * epsilon << std::endl;

	std::string scrubberRatingStr = Reduce(lines);
	std::string oxygenGeneratorRatingStr = Reduce(lines, true);

	unsigned long scrubberRating = std::stoul(scrubberRatingStr, nullptr, 2);
	unsigned long oxygenGeneratorRating = std::stoul(oxygenGeneratorRatingStr, nullptr, 2);

	std::cout << "The life support rating of the submarine is: " << scrubberRating * oxygenGeneratorRating << std::endl;
}