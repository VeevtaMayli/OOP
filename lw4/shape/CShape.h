#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape(const std::string& type, uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
	std::string ToString() const override;

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;

	std::string m_type;
	uint32_t m_outlineColor;
};
