#pragma once

class CStringStack
{
	struct Element
	{
		Element(const std::string& data, std::unique_ptr<Element>&& next);
		std::string data;
		std::unique_ptr<Element> next;
	};

public:
	CStringStack() = default;
	CStringStack(const CStringStack& other);
	CStringStack(CStringStack&& other);
	~CStringStack();
	void Push(const std::string& data);
	bool IsEmpty() const;
	std::string GetTop() const;
	void Pop();
	void Clear();
	CStringStack& operator=(const CStringStack& other);
	CStringStack& operator=(CStringStack&& other);

private:
	std::unique_ptr<Element> m_top;
};
