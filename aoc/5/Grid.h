#pragma once
#include "LineSegment.h"
#include <vector>

namespace Grid
{
	struct Cell
	{
		Linear::Point2D point = { 0, 0 };
		int intersections = 0;
	};

	
	using Grid = std::vector<Cell>;


	Grid MakeGrid(int xmin, int xmax, int ymin, int ymax);
}

