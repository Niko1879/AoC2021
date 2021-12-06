#include "LineSegment.h"
#include <algorithm>
#include "acstring.h"
#include <vector>

namespace Linear
{
	int _Plug(const LineSegment& line, const Point2D& p)
	{
		return line.a * p.y - line.b* p.x;
	}


	LineSegment FromPoints(const Point2D& p1, const Point2D& p2)
	{
		LineSegment line;

		line.a = p2.x - p1.x;
		line.b = p2.y - p1.y;
		line.c = _Plug(line, p1);
		line.xmin = std::min(p1.x, p2.x);
		line.xmax = std::max(p1.x, p2.x);
		line.ymin = std::min(p1.y, p2.y);
		line.ymax = std::max(p1.y, p2.y);

		return line;
	}


	bool PointLiesOnLine(const LineSegment& line, const Point2D& p)
	{
		if (p.x < line.xmin || p.y < line.ymin || p.x > line.xmax || p.y > line.ymax)
		{
			return false;
		}

		return _Plug(line, p) == line.c;
	}


	Point2D ParsePoint2D(const std::string& input)
	{
		std::vector<std::string> tokens = AcString::Split(input, ",");
		int x = std::stoi(tokens[0]);
		int y = std::stoi(tokens[1]);
		return Point2D{ x, y };
	}


	LineSegment ParseLineSegment(const std::string& input)
	{
		std::vector<std::string> tokens = AcString::Split(input, " -> ");
		Point2D p1 = ParsePoint2D(tokens[0]);
		Point2D p2 = ParsePoint2D(tokens[1]);
		return FromPoints(p1, p2);
	}


	bool IsHorizontal(const LineSegment& l)
	{
		return l.ymin == l.ymax;
	}


	bool IsVertical(const LineSegment& l)
	{
		return l.xmin == l.xmax;
	}
}