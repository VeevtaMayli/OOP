#include "pch.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "lw4/shape/CCircle.h"

using namespace std;

const double EPS = 1.0E-7;

bool IsEqual(const double a, const double b)
{
	return abs(a - b) < EPS;
}

SCENARIO("Possible to create and then obtain information about circle")
{
	GIVEN("center coordinate, radius, outline and fill colors")
	{
		CPoint center = { 1.0, 1.0 };
		double radius = 1.0;
		uint32_t outlineColor = 0x012345;
		uint32_t fillColor = 0x6789AB;

		WHEN("create circle")
		{
			CCircle circle(center, radius, outlineColor, fillColor);

			THEN("it contains the following parameters")
			{
				CHECK(circle.GetCenter() == center);
				CHECK(circle.GetRadius() == radius);
				CHECK(circle.GetOutlineColor() == outlineColor);
				CHECK(circle.GetFillColor() == fillColor);
				CHECK(IsEqual(circle.GetPerimeter(), 2 * M_PI * radius));
				CHECK(IsEqual(circle.GetArea(), M_PI * radius * radius));
			}

			AND_THEN("it return the following information")
			{
				string info = "Circle:\n"
							  "\tarea = 3.14\n"
							  "\tperimeter = 6.28\n"
							  "\toutline color = 012345\n"
							  "\tfill color = 6789ab\n"
							  "\tcenter(1.00, 1.00)\n"
							  "\tradius = 1.00\n";
				CHECK(circle.ToString() == info);
			}
		}
	}
}