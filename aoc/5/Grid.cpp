#include "Grid.h"

namespace Grid
{
	Grid MakeGrid(int xmin, int xmax, int ymin, int ymax)
	{
		Grid grid;
		for (int x = xmin; x <= xmax; ++x)
		{
			for (int y = ymin; y <= ymax; ++y)
			{
				Linear::Point2D point{ x, y };
				Cell cell{ point, 0 };
				grid.push_back(cell);
			}
		}

		return grid;
	}
}