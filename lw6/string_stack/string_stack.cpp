#include "pch.h"
#include "string_stack.h"

CStringStack::Element::Element(const std::string& data, std::unique_ptr<Element>&& next)
	: data(data)
	, next(std::move(next))
{
}

CStringStack::CStringStack(const CStringStack& other)
{
	*(this) = other;
}

CStringStack::CStringStack(CStringStack&& other)
	: m_top(std::move(other.m_top))
{
		other.m_top = nullptr;
}

CStringStack::~CStringStack()
{
	Clear();
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
	return !m_top;
}

std::string CStringStack::GetTop() const
{
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return m_top->data;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty");
	}
	m_top = std::move(m_top->next);
}

void CStringStack::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}