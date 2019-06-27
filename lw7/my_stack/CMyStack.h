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
		: CMyStack()
	{
		try
		{
			Element* src = other.m_top;
			Element** dst = &m_top;
			while (src)
			{
				*dst = new Element(src->data, nullptr);
				dst = &(*dst)->next;
				src = src->next;
			}
		}
		catch (...)
		{
			Clear();
			throw;
		}
	}

	CMyStack(CMyStack&& other) noexcept
		: m_top(other.m_top)
	{
		other.m_top = nullptr;
	}

	~CMyStack()
	{
		Clear();
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

	void Clear() noexcept
	{
		while (!IsEmpty())
		{
			Element* ptr = m_top;
			m_top = m_top->next;
			delete ptr;
		}

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
