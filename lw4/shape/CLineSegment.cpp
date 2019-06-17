#include "pch.h"
#include "CLineSegment.h"
#include "CPoint.h"

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor)
	: CShape("LineSegment", outlineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();
	// TODO: distance between p1 and p2
	return 0.0;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
