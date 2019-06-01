#include "pch.h"
#include "CShape.h"
#include "IShape.h"

using namespace std;

CShape::CShape(const string& type, uint32_t outlineColor)
	: m_type(type)
	, m_outlineColor(outlineColor)
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CShape::ToString() const
{
	ostringstream strm;
	strm << m_type << ":" << endl
		 << fixed << setprecision(2) << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\toutline color = " << setfill('0') << setw(6) << hex << GetOutlineColor() << endl;
	return strm.str();
}
