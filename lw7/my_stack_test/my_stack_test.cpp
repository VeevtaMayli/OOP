#include "pch.h"
#include "lw7/my_stack/CMyStack.h"

using namespace std;

template <typename T>
void IsEqual(CMyStack<T>& stack1, CMyStack<T>& stack2)
{
	while (!stack1.IsEmpty() && !stack2.IsEmpty())
	{
		CHECK(stack1.GetTop() == stack2.GetTop());
		stack1.Pop();
		stack2.Pop();
	}
	CHECK(stack1.IsEmpty());
	CHECK(stack2.IsEmpty());
}

TEST_CASE("stack of int")
{
	CMyStack<int> stack;

	SECTION("get top and pop of empty stack")
	{
		CHECK(stack.IsEmpty());
		CHECK_THROWS_WITH(stack.GetTop(), "Stack is empty");
		CHECK_THROWS_WITH(stack.Pop(), "Stack is empty");
	}

	SECTION("push one element, get top and pop")
	{
		stack.Push(1);
		CHECK_FALSE(stack.IsEmpty());
		CHECK(stack.GetTop() == 1);
		CHECK_NOTHROW(stack.Pop());
		CHECK_THROWS_WITH(stack.GetTop(), "Stack is empty");
		CHECK(stack.IsEmpty());
	}

	SECTION("push some elements")
	{
		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		CHECK_FALSE(stack.IsEmpty());

		SECTION("using copy constructor")
		{
			CMyStack<int> copy(stack);
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using copy assignment operator")
		{
			CMyStack<int> copy = stack;
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using move constructor")
		{
			CMyStack<int> copy = stack;
			CMyStack<int> other(move(stack));

			CHECK(stack.IsEmpty());
			IsEqual(copy, other);
		}

		SECTION("using move assignment operator")
		{
			CMyStack<int> copy = stack;
			CMyStack<int> other = move(stack);

			CHECK(stack.IsEmpty());
			IsEqual(copy, other);
		}

		SECTION("clear stack")
		{
			CHECK_NOTHROW(stack.Clear());
			CHECK(stack.IsEmpty());
		}
	}
}

TEST_CASE("stack of string")
{
	CMyStack<string> stack;

	SECTION("get top and pop of empty stack")
	{
		CHECK(stack.IsEmpty());
		CHECK_THROWS_WITH(stack.GetTop(), "Stack is empty");
		CHECK_THROWS_WITH(stack.Pop(), "Stack is empty");
	}

	SECTION("push one element, get top and pop")
	{
		stack.Push("test");
		CHECK_FALSE(stack.IsEmpty());
		CHECK(stack.GetTop() == "test");
		CHECK_NOTHROW(stack.Pop());
		CHECK_THROWS_WITH(stack.GetTop(), "Stack is empty");
		CHECK(stack.IsEmpty());
	}

	SECTION("push some elements")
	{
		stack.Push("test");
		stack.Push("my");
		stack.Push("stack");
		CHECK_FALSE(stack.IsEmpty());

		SECTION("using copy constructor")
		{
			CMyStack<string> copy(stack);
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using copy assignment operator")
		{
			CMyStack<string> copy = stack;
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using move constructor")
		{
			CMyStack<string> copy = stack;
			CMyStack<string> other(move(stack));

			CHECK(stack.IsEmpty());
			IsEqual(copy, other);
		}

		SECTION("using move assignment operator")
		{
			CMyStack<string> copy;
			copy = stack;
			CMyStack<string> other = move(stack);

			CHECK(stack.IsEmpty());
			IsEqual(copy, other);
		}

		SECTION("clear stack")
		{
			CHECK_NOTHROW(stack.Clear());
			CHECK(stack.IsEmpty());
		}
	}
}