#include "pch.h"
#include "CSolidShape.h"

using namespace std;

CSolidShape::CSolidShape(const string& type, uint32_t outlineColor, uint32_t fillColor)
	: CShape::CShape(type, outlineColor)
	, m_fillColor(fillColor)
{
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

string CSolidShape::ToString() const
{
	return CShape::ToString();
}

void CSolidShape::AppendProperties(std::ostream& strm) const
{
	strm << "\tfill color = " << setfill('0') << setw(6) << hex << GetFillColor() << endl;
	AppendSolidShapeChildProperties(strm);
}
