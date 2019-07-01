#include "pch.h"
#include "lw6/string_stack/string_stack.h"

using namespace std;

void IsEqual(CStringStack& stack1, CStringStack& stack2)
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

TEST_CASE("stack of string")
{
	CStringStack stack;

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
			CStringStack copy(stack);
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using copy assignment operator")
		{
			CStringStack copy = stack;
			CHECK_FALSE(stack.IsEmpty());
			IsEqual(stack, copy);
		}

		SECTION("using move constructor")
		{
			CStringStack copy = stack;
			CStringStack other(move(stack));

			CHECK(stack.IsEmpty());
			IsEqual(copy, other);
		}

		SECTION("using move assignment operator")
		{
			CStringStack copy;
			copy = stack;
			CStringStack other = move(stack);

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