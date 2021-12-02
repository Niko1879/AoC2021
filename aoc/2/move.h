#pragma once
#include <vector>
#include <string>

struct Position
{
	int x = 0;
	int y = 0;
	int aim = 0;
};

enum class Direction
{
	FORWARD,
	DOWN,
	UP
};

struct Instruction
{
	Direction direction = Direction::FORWARD;
	int amount = 0;
};

Instruction Decode(const std::string& instruction);

Position Traverse(const std::vector<Instruction>& instructions, Position start = { 0, 0, 0}, bool useAim = false);