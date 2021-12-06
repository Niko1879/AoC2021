#include "LineSegment.h"
#include "Grid.h"
#include "IO.h"
#include <iostream>

int main()
{
	std::vector<std::string> lines = IO::ReadLines("input.txt");
	std::vector<Linear::LineSegment> lineSegments;
	int xmin = INT_MAX, xmax = -INT_MAX, ymin = INT_MAX, ymax = -INT_MAX;
	for (const std::string& line : lines)
	{
		Linear::LineSegment lineSegment = Linear::ParseLineSegment(line);
		lineSegments.push_back(lineSegment);
		if (lineSegment.xmin < xmin) xmin = lineSegment.xmin;
		if (lineSegment.ymin < ymin) ymin = lineSegment.ymin;
		if (lineSegment.xmax > xmax) xmax = lineSegment.xmax;
		if (lineSegment.ymax > ymax) ymax = lineSegment.ymax;
	}

	Grid::Grid grid = Grid::MakeGrid(xmin, xmax, ymin, ymax);
	for (Grid::Cell& cell : grid)
	{
		for (const Linear::LineSegment& lineSegment : lineSegments)
		{
			//uncomment for part 1 solution

			/*if (!(Linear::IsHorizontal(lineSegment) || Linear::IsVertical(lineSegment)))
			{
				continue;
			}*/

			if (Linear::PointLiesOnLine(lineSegment, cell.point))
			{
				++cell.intersections;
			}
		}
	}

	int numIntersections = 0;
	for (const Grid::Cell& cell : grid)
	{
		if (cell.intersections > 1)
		{
			++numIntersections;
		}
	}

	std::cout << "The number of points at which at least 2 lines overlap is: " << numIntersections << std::endl;
}