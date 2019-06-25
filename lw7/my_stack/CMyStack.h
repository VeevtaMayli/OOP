#pragma once

template <typename T>
class CMyStack
{
	struct Element
	{
		Element(const T& data, Element* next)
			: data(data)
			, next(next)
		{
		}
		T data;
		Element* next;
	};

public:
	CMyStack() = default;

	CMyStack(const CMyStack& other)
	{
	}

	CMyStack(CMyStack&& stack)
	{
	}

	~CMyStack()
	{
	}

	bool IsEmpty() const noexcept
	{
		return !m_top;
	}

	void Push(const T& data)
	{
		Element* newElement = new Element(data, m_top);
		m_top = newElement;
	}

	void Pop()
	{
		if (!IsEmpty())
		{
			Element* ptr = m_top;
			m_top = m_top->next;
			delete ptr;
		}
		else
		{
			throw std::out_of_range("Stack is empty");
		}
	}

	const T& GetTop() const
	{
		if (!IsEmpty())
		{
			return m_top->data;
		}
		else
		{
			throw std::out_of_range("Stack is empty");
		}
	}

	void Clear()
	{

	}

	CMyStack& operator=(const CMyStack& other)
	{

	}

	CMyStack& operator=(CMyStack&& other)
	{

	}

private:
	Element* m_top = nullptr;
};
