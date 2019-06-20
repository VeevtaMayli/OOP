#include "pch.h"
#include "CCircle.h"

using namespace std;

CCircle::CCircle(CPoint const& center, double const radius, uint32_t outlineColor, uint32_t fillColor)
	: CSolidShape("Circle", outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
