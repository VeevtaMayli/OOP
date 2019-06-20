#pragma once
#include "CShape.h"
#include "ISolidShape.h"

class CSolidShape
	: public ISolidShape
	, public CShape
{
public:
	CSolidShape(const std::string& type, uint32_t outlineColor, uint32_t fillColor);
	uint32_t GetFillColor() const final;
	uint32_t GetOutlineColor() const final;
	std::string ToString() const final;

private:
	std::string m_type;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};
