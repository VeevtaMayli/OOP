#include "pch.h"
#include "equation4.h"

const double EPS = 1.0E-7;

int Sign(double value)
{
	return value > 0 ? 1 : (value < 0 ? -1 : 0);
}

bool IsEqual(double x, double y)
{
	return abs(x - y) < EPS;
}

EquationRoot Solve2(double a, double b, double c)
{
	EquationRoot roots;
	
	double d = pow(b, 2) - 4 * a * c;
	
	if (IsEqual(d, 0.0))
	{
		roots.push_back(-b / (2 * a));
	}
	else if (d > 0)
	{
		roots.push_back((-b + sqrt(d)) / (2 * a));
		roots.push_back((-b - sqrt(d)) / (2 * a));
	}
	
	std::sort(roots.begin(), roots.end());
	return roots;
}

EquationRoot Solve3(double a, double b, double c, double d)
{
	EquationRoot roots;
	
	double a0 = a;
	a = b / a0;
	b = c / a0;
	c = d / a0;

	double r = (2.0 * pow(a, 3) - 9.0 * a * b + 27 * c) / 54;
	double q = (pow(a, 2) - 3 * b) / 9;
	double s = (pow(q, 3) - pow(r, 2));
	
	if (IsEqual(s, 0.0))
	{
		roots.push_back(-2 * Sign(r) * sqrt(q) - a / 3);
		roots.push_back(Sign(r) * sqrt(q) - a / 3);
	}
	else if (s > 0)
	{
		double f = acos(r / sqrt(pow(q, 3))) / 3;
		roots.push_back(-2 * sqrt(q) * cos(f) - a / 3);
		roots.push_back(-2 * sqrt(q) * cos(f - 2.0 * M_PI / 3) - a / 3);
		roots.push_back(-2 * sqrt(q) * cos(f + 2.0 * M_PI / 3) - a / 3);
	}
	else if (s < 0)
	{
		double x;

		if (IsEqual(q, 0.0))
		{
			x = -Sign(c - pow(a, 3) / 27) * pow(abs((c - pow(a, 3) / 27)), 1 / 3) - a / 3;
		}
		else if (q > 0)
		{
			x = -2.0 * Sign(r) * sqrt(q) * cosh(acosh(abs(r) / sqrt(pow(q, 3))) / 3) - a / 3;
		}
		else if (q < 0)
		{
			x = -2.0 * Sign(r) * sqrt(abs(q)) * sinh(sinh(abs(r) / sqrt(pow(abs(q), 3))) / 3) - a / 3;
		}
		roots.push_back(x);
	}
	sort(roots.begin(), roots.end());
	return roots;
}

EquationRoot Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw std::invalid_argument("Argument of supreme degree cannot be equal to zero");
	}

	double a0 = a;
	a = b / a0;
	b = c / a0;
	c = d / a0;
	d = e / a0;
	
	EquationRoot roots3 = Solve3(1, -b, a * c - 4 * d, -pow(a, 2) * d + 4 * b * d - pow(c, 2));

	double y0 = roots3[roots3.size() - 1];
	double r = sqrt(pow(a, 2) / 4.0 - b + y0);
	double q =(a / 2.0 * y0 - c) < 0 ? -sqrt(pow(y0, 2) / 4.0 - d) : sqrt(pow(y0, 2) / 4.0 - d);

	EquationRoot roots21 = Solve2(1, a / 2.0 + r, y0 / 2.0 + q);
	EquationRoot roots22 = Solve2(1, a / 2.0 - r, y0 / 2.0 - q);

	EquationRoot roots;
	std::set_union(roots21.begin(), roots21.end(), roots22.begin(), roots22.end(), std::back_inserter(roots));

	if (roots.empty())
	{
		throw std::domain_error("There are no rational roots");
	}

	std::sort(roots.begin(), roots.end());
	return roots;
}
