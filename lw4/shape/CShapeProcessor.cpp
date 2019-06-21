#include "pch.h"
#include "CShapeProcessor.h"

using namespace std;

CShapeProcessor::CShapeProcessor(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({ { "Circle", bind(&CShapeProcessor::AddCircle, this, placeholders::_1) },
		  { "LineSegment", bind(&CShapeProcessor::AddLineSegment, this, placeholders::_1) },
		  { "Rectangle", bind(&CShapeProcessor::AddRectangle, this, placeholders::_1) },
		  { "Triangle", bind(&CShapeProcessor::AddTriangle, this, placeholders::_1) } })
{
}

bool CShapeProcessor::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

void CShapeProcessor::Info() const
{
	for (const auto& shape : m_shapeList)
	{
		m_output << shape->ToString() << endl;
	}
}

void CShapeProcessor::PrintShapeWithMinPerimeter() const
{
}

void CShapeProcessor::PrintShapeWithMaxArea() const
{
}

bool CShapeProcessor::AddCircle(std::istream& args)
{
}

bool CShapeProcessor::AddLineSegment(std::istream& args)
{
}

bool CShapeProcessor::AddRectangle(std::istream& args)
{
}

bool CShapeProcessor::AddTriangle(std::istream& args)
{
}

std::vector<std::string> CShapeProcessor::ParseShapeString(std::istream& strm)
{
	vector<string> params;
	string param;

	while (getline(strm, param, ' '))
	{
		params.push_back(param);
	}
	return params;
}
