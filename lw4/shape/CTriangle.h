#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CTriangle final : public CSolidShape
{
public:
	CTriangle();
	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
