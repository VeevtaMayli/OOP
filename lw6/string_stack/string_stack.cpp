#include "pch.h"
#include "string_stack.h"

CStringStack::Element::Element(const std::string& data, std::unique_ptr<Element>&& next)
	: data(data)
	, next(std::move(next))
{
}

CStringStack::CStringStack(const CStringStack& other)
{

}

CStringStack::CStringStack(CStringStack&& other)
{

}

CStringStack::~CStringStack()
{

}

CStringStack& CStringStack::operator=(const CStringStack& other)
{

}

CStringStack& CStringStack::operator=(CStringStack&& other)
{

}

void CStringStack::Push(const std::string& data)
{

}

bool CStringStack::IsEmpty() const
{

}

std::string CStringStack::GetTop() const
{

}

void CStringStack::Pop()
{

}

void CStringStack::Clear()
{

}