#include "pch.h"
#include "lw4/shape/CShapeProcessor.h"

using namespace std;

SCENARIO("Check the count of circle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("shape processor")
	{
		CShapeProcessor sp(input, output);

		WHEN("user enter circle with not all arguments")
		{
			input << "Circle 0.00 3.00";

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Circle center.x center.y radius [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("Check the count of triangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("shape processor")
	{
		CShapeProcessor sp(input, output);

		WHEN("user enter triangle with not all arguments")
		{
			input << "Triangle 1.00 2.00 1 3";

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex3.y [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("Check the count of rectangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("shape processor")
	{
		CShapeProcessor sp(input, output);

		WHEN("user enter rectangle with not all arguments")
		{
			input << "Rectangle 0.00 1.00 5.00";

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y [outline] [fill]\n");
			}
		}
	}
}

SCENARIO("Check the count of line segment arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("shape processor")
	{
		CShapeProcessor sp(input, output);

		WHEN("user enter lineSegment with not all arguments")
		{
			input << "LineSegment 0.00 0.00 1.00";

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(sp.HandleCommand(), "Incorrect count of arguments!\nUsage: LineSegment start.x start.y end.x end.y [outline]\n");
			}
		}
	}
}

SCENARIO("Search max area and min perimeter")
{
	stringstream input;
	ostringstream output;

	GIVEN("shape processor")
	{
		CShapeProcessor sp(input, output);

		WHEN("user enter circle, rectangle, triangle and line segment")
		{
			input << "Rectangle 2.0 0 0 4.0\n";
			sp.HandleCommand();
			input << "Circle 0 0 5.0\n";
			sp.HandleCommand();
			input << "Triangle 0 1.0 2.0 3.0 0 3.0 ff0000 00ff99\n";
			sp.HandleCommand();
			input << "LineSegment 0 1.0 2.0 3.0 ff2200\n";
			sp.HandleCommand();

			THEN("print shape with max area and min perimeter")
			{
				string result = "Shape with max area is Circle:\n"
								"\tarea = 78.54\n"
								"\tperimeter = 31.42\n"
								"\toutline color = 000000\n"
								"\tfill color = ffffff\n"
								"\tcenter(0.00, 0.00)\n"
								"\tradius = 5.00\n\n"
								"Shape with min perimeter is LineSegment:\n"
								"\tarea = 0.00\n"
								"\tperimeter = 2.83\n"
								"\toutline color = ff2200\n"
								"\tstart point(0.00, 1.00)\n"
								"\tend point(2.00, 3.00)\n\n";

				sp.PrintShapeWithMaxArea();
				sp.PrintShapeWithMinPerimeter();
				CHECK(output.str() == result);
			}
		}
	}
}