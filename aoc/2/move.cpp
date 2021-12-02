#include "move.h"
#include "acstring.h"
#include <stdexcept>


Instruction Decode(const std::string& instruction)
{
	std::vector<std::string> tokens = acstring::Split(instruction, " ");
	
	Direction direction = Direction::FORWARD;
	std::string directionStr = tokens[0];
	if (directionStr == "forward")
		direction = Direction::FORWARD;
	else if (directionStr == "down")
		direction = Direction::DOWN;
	else if (directionStr == "up")
		direction = Direction::UP;
	else
	{
		throw std::invalid_argument("Unknown direction: " + directionStr);
	}

	int amount = stoi(tokens[1]);

	return Instruction{ direction, amount};
}


Position Traverse(const std::vector<Instruction>& instructions, Position start, bool useAim)
{
	for (Instruction instruction : instructions)
	{
		switch (instruction.direction)
		{
			case Direction::FORWARD:
				start.x += instruction.amount;
				if (useAim)
					start.y += instruction.amount * start.aim;
				break;

			case Direction::DOWN:
				(useAim) ? start.aim += instruction.amount : start.y += instruction.amount;
				break;

			case Direction::UP:
				(useAim) ? start.aim -= instruction.amount : start.y -= instruction.amount;
				break;
		}
	}
	
	return start;
}