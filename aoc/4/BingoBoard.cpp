#include "BingoBoard.h"
#include "acstring.h"

BingoBoard::BingoBoard() : marked(0), board{0}
{

}


BingoBoard BingoBoard::Parse(const std::vector<std::string>& input)
{
	BingoBoard board;
	int i = 0;
	for (const std::string& line : input)
	{
		std::vector<std::string> numbers = AcString::Split(line, " ");

		for (const std::string& number : numbers)
		{
			if (number == "") 
				continue;
			board.board[i++] = std::stoi(number);
		}
	}

	return board;
}

void BingoBoard::Call(int number)
{
	for (int i = 0; i < 25; ++i)
	{
		if (board[i] == number)
		{
			marked |= (0x1000000 >> i);
			break;
		}
	}
}

bool BingoBoard::HasBingo() const
{
	for (unsigned i = 0x1F00000; i; i = i >> 5)
	{
		if ((marked & i) == i)
			return true;
	}

	unsigned magic = 0x1084210;
	for (int i = 0; i < 5; ++i)
	{
		if ((marked & magic) == magic)
			return true;

		magic = magic >> 1;
	}

	return false;
}

int BingoBoard::SumUnmarked() const
{
	unsigned magic = 0x1000000;
	int sum = 0;
	for (int i : board)
	{
		if (!(magic & marked))
		{
			sum += i;
		}

		magic = magic >> 1;
	}

	return sum;
}