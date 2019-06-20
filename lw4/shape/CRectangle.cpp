#include "pch.h"
#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint const& leftTop, CPoint const& rightBottom, uint32_t outlineColor, uint32_t fillColor)
	: CSolidShape("Rectangle", outlineColor, fillColor)
	, m_leftTop(leftTop)
	, m_rightBottom(m_rightBottom)
{
}

double CRectangle::GetArea() const
{
	return GetHeight() * GetWidth();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetHeight() + GetWidth());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return abs(GetLeftTop().x - GetRightBottom().x);
}

double CRectangle::GetHeight() const
{
	return abs(GetLeftTop().y - GetRightBottom().y);
}
