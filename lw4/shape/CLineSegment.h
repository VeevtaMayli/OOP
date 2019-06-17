#pragma once
#include "CPoint.h"
#include "CShape.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
