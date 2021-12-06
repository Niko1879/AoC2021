#pragma once
#include <vector>
#include <string>
class BingoBoard
{
public:
	BingoBoard();

	void Call(int number);

	bool HasBingo() const;

	int SumUnmarked() const;

	static BingoBoard Parse(const std::vector<std::string>& input);

private:
	unsigned marked;
	int board[25];
};

