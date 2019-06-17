#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle final : public CSolidShape
{
public:
	CCircle();
	double GetArea() const override;
	double GetPerimeter() const override;

	double GetRadius() const;
	CPoint GetCenter() const;

private:
	CPoint m_center;
	double m_radius;
};
