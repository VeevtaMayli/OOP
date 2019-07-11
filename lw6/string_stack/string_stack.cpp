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
		Element* node = other.m_top.get();
		std::unique_ptr<Element> element = std::make_unique<Element>(node->data, nullptr);
		std::unique_ptr<Element> top = std::make_unique<Element>(element->data, nullptr);

		node = node->next.get();
		while (node)
		{
			element->next = std::make_unique<Element>(node->data, nullptr);
			element = std::move(element->next);
			node = node->next.get();
		}
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