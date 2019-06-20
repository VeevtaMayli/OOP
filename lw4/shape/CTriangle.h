#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CTriangle final : public CSolidShape
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	void AppendSolidShapeChildProperties(std::ostream& strm) const;

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
