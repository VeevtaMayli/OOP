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

	bool IsEmpty() const
	{
	
	}

	void Push(const T& data)
	{

	}

	void Pop()
	{

	}

	const T& GetTop() const
	{

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
