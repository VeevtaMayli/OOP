#include "pch.h"
#include "lw4/shape/CTriangle.h"

using namespace std;

SCENARIO("Possible to create and then obtain information about triangle")
{
	GIVEN("coordinate of three vertex, outline and fill colors")
	{
		CPoint vertex1 = { 0.0, 0.0 };
		CPoint vertex2 = { 3.0, 0.0 };
		CPoint vertex3 = { 0.0, 4.0 };
		uint32_t outlineColor = 0x012345;
		uint32_t fillColor = 0x6789AB;

		WHEN("create rectangle")
		{
			CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

			THEN("it contains the following parameters")
			{
				CHECK(triangle.GetVertex1() == vertex1);
				CHECK(triangle.GetVertex2() == vertex2);
				CHECK(triangle.GetVertex3() == vertex3);
				CHECK(triangle.GetOutlineColor() == outlineColor);
				CHECK(triangle.GetFillColor() == fillColor);
				CHECK(triangle.GetPerimeter() == 12.00);
				CHECK(triangle.GetArea() == 6.00);
			}

			AND_THEN("it return the following information")
			{
				string info = "Triangle:\n"
							  "\tarea = 6.00\n"
							  "\tperimeter = 12.00\n"
							  "\toutline color = 012345\n"
							  "\tfill color = 6789ab\n"
							  "\tvertex1(0.00, 0.00)\n"
							  "\tvertex2(3.00, 0.00)\n"
							  "\tvertex3(0.00, 4.00)\n";
				CHECK(triangle.ToString() == info);
			}
		}
	}
}