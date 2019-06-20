#include "pch.h"
#include "CTriangle.h"

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor)
	: CSolidShape("Triangle", outlineColor, fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double CTriangle::GetArea() const
{
	double side1 = GetDistance(m_vertex1, m_vertex2);
	double side2 = GetDistance(m_vertex2, m_vertex3);
	double side3 = GetDistance(m_vertex1, m_vertex3);
	double halfPerimeter = (side1 + side2 + side3) / 2;
	return sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
}

double CTriangle::GetPerimeter() const
{
	return GetDistance(m_vertex1, m_vertex2) + GetDistance(m_vertex2, m_vertex3) + GetDistance(m_vertex1, m_vertex3);
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
