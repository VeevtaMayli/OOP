#include "pch.h"
#include "CPoint.h"

double GetDistance(const CPoint& point1, const CPoint& point2)
{
	return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}
