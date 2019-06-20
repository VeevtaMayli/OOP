#pragma once

class CPoint
{
public:
	bool operator==(CPoint const& other) const;

	double x;
	double y;
};

double GetDistance(const CPoint& point1, const CPoint& point2);
