#pragma once

#include <string>

namespace Linear
{
	struct LineSegment
	{
		int a = 0;
		int b = 0;
		int c = 0;
		int xmin = 0;
		int ymin = 0;
		int xmax = 0;
		int ymax = 0;
	};


	struct Point2D
	{
		int x = 0;
		int y = 0;
	};


	LineSegment FromPoints(const Point2D& p1, const Point2D& p2);


	bool PointLiesOnLine(const LineSegment& line, const Point2D& p);


	Point2D ParsePoint2D(const std::string& input);

	
	LineSegment ParseLineSegment(const std::string& input);


	bool IsHorizontal(const LineSegment& l);


	bool IsVertical(const LineSegment& l);
}

