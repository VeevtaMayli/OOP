#pragma once
#include <boost/noncopyable.hpp>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"

class CShapeProcessor : boost::noncopyable
{
public:
	CShapeProcessor(std::istream& input, std::ostream& output);
	bool HandleCommand();
	void Info() const;
	void PrintShapeWithMinPerimeter() const;
	void PrintShapeWithMaxArea() const;

private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;
	
	bool AddCircle(std::istream& args);
	bool AddLineSegment(std::istream& args);
	bool AddRectangle(std::istream& args);
	bool AddTriangle(std::istream& args);
	std::vector<std::string> ParseShapeString(std::istream& strm);

	std::vector<std::shared_ptr<IShape>> m_shapeList;
	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;
};
