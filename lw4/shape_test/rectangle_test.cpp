#include "pch.h"
#include "lw4/shape/CRectangle.h"

using namespace std;

SCENARIO("Possible to create and then obtain information about rectangle")
{
	GIVEN("left top and right bottom coordinate, outline and fill colors")
	{
		CPoint leftTop = { 0.0, 1.0 };
		CPoint rightBottom = { 1.0, 0.0 };
		uint32_t outlineColor = 0x012345;
		uint32_t fillColor = 0x6789AB;

		WHEN("create rectangle")
		{
			CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);

			THEN("it contains the following parameters")
			{
				CHECK(rectangle.GetLeftTop() == leftTop);
				CHECK(rectangle.GetRightBottom() == rightBottom);
				CHECK(rectangle.GetOutlineColor() == outlineColor);
				CHECK(rectangle.GetFillColor() == fillColor);
				CHECK(rectangle.GetHeight() == 1.00);
				CHECK(rectangle.GetWidth() == 1.00);
				CHECK(rectangle.GetPerimeter() == 4.00);
				CHECK(rectangle.GetArea() == 1.00);
			}

			AND_THEN("it return the following information")
			{
				string info = "Rectangle:\n"
							  "\tarea = 1.00\n"
							  "\tperimeter = 4.00\n"
							  "\toutline color = 012345\n"
							  "\tfill color = 6789ab\n"
							  "\tleft top(0.00, 1.00)\n"
							  "\tright bottom(1.00, 0.00)\n"
							  "\twidth = 1.00\n"
							  "\theight = 1.00\n";
				CHECK(rectangle.ToString() == info);
			}
		}
	}
}