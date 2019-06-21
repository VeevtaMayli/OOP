#include "pch.h"
#include "lw4/shape/CShapeProcessor.h"

using namespace std;

SCENARIO("check the count of circle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter circle with not all arguments")
		{
			input << "Circle 0.00 3.00";
			CShapeProcessor sp(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Circle center.x center.y radius [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("check the count of triangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter triangle with not all arguments")
		{
			input << "Triangle 1.00 2.00 1 3";
			CShapeProcessor sp(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("check the nucountmber of rectangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter rectangle with not all arguments")
		{
			input << "Rectangle 0.00 1.00 5.00";
			CShapeProcessor sp(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("check the count of line segment arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter lineSegment with not all arguments")
		{
			input << "LineSegment 0.00 0.00 1.00";
			CShapeProcessor sp(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: LineSegment start.x start.y end.x end.y [outline]\n");
			}
		}
	}
}