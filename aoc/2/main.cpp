#include "move.h"
#include "IO.h"
#include <iostream>

int main()
{
	std::vector<std::string> lines = IO::ReadLines("input.txt");
	std::vector<Instruction> instructions;
	for (const std::string& line : lines)
	{
		instructions.push_back(Decode(line));
	}

	Position position = Traverse(instructions);

	//part 1
	std::cout << "The product of depth and horizontal position is: " << position.x * position.y << std::endl;

	//part 2
	position = Traverse(instructions, Position{ 0, 0, 0 }, true);
	std::cout << "The product of depth and horizontal position is: " << position.x * position.y << std::endl;
}