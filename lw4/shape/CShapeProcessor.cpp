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
	vector<string> params = ParseShapeString(args);

	if (params.size() != 4 && params.size() != 6)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Circle center.x center.y radius [outline] [fill]\n");
	}

	CPoint center = { stod(params[1]), stod(params[2]) };
	double radius = stod(params[3]);
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (params.size() == 6)
	{
		outlineColor = stoul(params[4], nullptr, 16);
		fillColor = stoul(params[5], nullptr, 16);
	}

	auto circle = make_shared<CCircle>(center, radius, outlineColor, fillColor);
	m_shapeList.push_back(circle);

	return true;
}

bool CShapeProcessor::AddLineSegment(std::istream& args)
{
	vector<string> params = ParseShapeString(args);

	if (params.size() != 5 && params.size() != 6)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: LineSegment start.x start.y end.x end.y [outline]\n");
	}

	CPoint startPoint = { stod(params[1]), stod(params[2]) };
	CPoint endPoint = { stod(params[3]), stod(params[4]) };
	uint32_t outlineColor = 0x000000;

	if (params.size() == 6)
	{
		outlineColor = stoul(params[5], nullptr, 16);
	}

	auto lineSegment = make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapeList.push_back(lineSegment);

	return true;
}

bool CShapeProcessor::AddRectangle(std::istream& args)
{
	vector<string> params = ParseShapeString(args);

	if (params.size() != 5 && params.size() != 7)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y [outline] [fill]\n");
	}

	CPoint leftTop = { stod(params[1]), stod(params[2]) };
	CPoint rightBottom = { stod(params[3]), stod(params[4]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (params.size() == 7)
	{
		outlineColor = stoul(params[5], nullptr, 16);
		fillColor = stoul(params[6], nullptr, 16);
	}

	auto rectangle = make_shared<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
	m_shapeList.push_back(rectangle);

	return true;
}

bool CShapeProcessor::AddTriangle(std::istream& args)
{
	vector<string> params = ParseShapeString(args);

	if (params.size() != 7 && params.size() != 9)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y [outline] [fill]\n");
	}

	CPoint vertex1 = { stod(params[1]), stod(params[2]) };
	CPoint vertex2 = { stod(params[3]), stod(params[4]) };
	CPoint vertex3 = { stod(params[5]), stod(params[6]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (params.size() == 9)
	{
		outlineColor = stoul(params[8], nullptr, 16);
		fillColor = stoul(params[9], nullptr, 16);
	}

	auto triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	m_shapeList.push_back(triangle);

	return true;
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
