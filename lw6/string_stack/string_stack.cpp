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
	if (this != &other)
	{
		CStringStack tempStack(other);
		m_top.swap(tempStack.m_top);
	}
	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& other)
{
	if (this != &other)
	{
		Clear();
		m_top = std::move(other.m_top);
		other.m_top = nullptr;
	}
	return *this;
}

void CStringStack::Push(const std::string& data)
{
	auto newElement= std::make_unique<Element>(data, std::move(m_top));
	m_top = std::move(newElement);
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