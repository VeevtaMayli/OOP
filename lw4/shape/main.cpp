#include "pch.h"
#include "CShapeProcessor.h"
#include "IShape.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		CShapeProcessor processor(cin, cout);
		while (!cin.eof() && !cin.fail())
		{
			if (!processor.HandleCommand())
			{
				cout << "Unknown command!\nUsage: Circle, Trinagle, Rectangle or LineSegment with parameters" << endl;
			}
		}
		processor.PrintShapeWithMaxArea();
		processor.PrintShapeWithMinPerimeter();
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;

		return 1;
	}

	return 0;
}