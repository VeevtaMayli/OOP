#include "pch.h"
#include "equation4.h"

bool GetCoefficients(std::istream& inStrm, double& a, double& b, double& c, double& d, double& e)
{
	return (inStrm >> a) && (inStrm >> b) && (inStrm >> c) && (inStrm >> d) && (inStrm >> e);
}

int main()
{
	double a, b, c, d, e;
	while (GetCoefficients(std::cin, a, b, c, d, e))
	{
		try
		{
			EquationRoot roots = Solve4(a, b, c, d, e);
			std::copy(roots.begin(), roots.end(), std::ostream_iterator<double>(std::cout, " "));
			std::cout << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}