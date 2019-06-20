#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle final : public CSolidShape
{
public:
	CRectangle(CPoint const& leftTop, CPoint const& rightBottom, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	void AppendSolidShapeChildProperties(std::ostream& strm) const;

	CPoint m_leftTop;
	CPoint m_rightBottom;
};
