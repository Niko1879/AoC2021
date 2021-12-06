#include "BingoBoard.h"
#include "IO.h"
#include "acstring.h"
#include <iostream>


int Procedure(std::vector<BingoBoard> boards, std::vector<int> callouts, bool last = false)
{
	int winningIndex = 0;
	int leastNumTurns = (last) ? 0 : INT_MAX;
	int winningCallout = 0;
	for (int i = 0; i < boards.size(); ++i)
	{
		BingoBoard& board = boards[i];
		int numTurns = 0;
		for (int callout : callouts)
		{
			board.Call(callout);
			if (board.HasBingo())
			{
				if ((last) ? numTurns > leastNumTurns : numTurns < leastNumTurns)
				{
					winningIndex = i;
					leastNumTurns = numTurns;
					winningCallout = callout;
				}

				break;
			}

			++numTurns;
		}
	}

	BingoBoard winner = boards[winningIndex];
	int score = winner.SumUnmarked() * winningCallout;

	return score;
}


int main()
{
	std::vector<std::string> lines = IO::ReadLines("input.txt");
	std::vector<std::vector<std::string>> groups = AcString::Split(lines, "");
	std::vector<std::string> calloutStrings = groups[0];
	std::vector<int> callouts;
	std::vector<BingoBoard> boards;
	
	for (const std::string& line : calloutStrings)
	{
		std::vector<std::string> tokens = AcString::Split(line, ",");
		for (const std::string& token : tokens)
		{
			callouts.push_back(std::stoi(token));
		}
	}

	for (int i = 1; i < groups.size(); ++i)
	{
		std::vector<std::string> boardStr = groups[i];
		BingoBoard board = BingoBoard::Parse(boardStr);
		boards.push_back(board);
	}

	std::cout << "The winning score is: " << Procedure(boards, callouts) << std::endl;
	std::cout << "The losing score is: " << Procedure(boards, callouts, true) << std::endl;
}