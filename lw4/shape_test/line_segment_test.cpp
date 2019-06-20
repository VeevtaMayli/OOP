#include "pch.h"
#include "lw4/shape/CLineSegment.h"

using namespace std;

SCENARIO("Possible to create and then obtain information about line segment")
{
	GIVEN("2 points and outline color")
	{
		CPoint startPoint = { 0.0, 0.0 };
		CPoint endPoint = { -1.0, 0.0 };
		uint32_t outlineColor = 0xABCDEF;

		WHEN("create line segment")
		{
			CLineSegment lineSegment(startPoint, endPoint, outlineColor);

			THEN("it contains the following parameters")
			{
				CHECK(lineSegment.GetStartPoint() == startPoint);
				CHECK(lineSegment.GetEndPoint() == endPoint);
				CHECK(lineSegment.GetOutlineColor() == outlineColor);
				CHECK(lineSegment.GetArea() == 0.0);
				CHECK(lineSegment.GetPerimeter() == 1.0);
			}

			AND_THEN("it return the following information")
			{
				string info = "LineSegment:\n"
							  "\tarea = 0.00\n"
							  "\tperimeter = 1.00\n"
							  "\toutline color = abcdef\n"
							  "\tstart point(0.00, 0.00)\n"
							  "\tend point(-1.00, 0.00)\n";
				CHECK(lineSegment.ToString() == info);
			}
		}
	}
}