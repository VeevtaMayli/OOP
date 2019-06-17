#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle final : public CSolidShape
{
public:
	CRectangle();
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};
