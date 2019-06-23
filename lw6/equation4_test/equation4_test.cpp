#include "pch.h"
#include "lw6/equation4/equation4.h"

bool SolutionIsEqualToExpected(const EquationRoot& roots, int numRoots, const EquationRoot& expectedRoots)
{
	if (roots.size() != numRoots)
		return false;	

	for (int i = 0; i < numRoots; i++)
		if (abs(roots[i] - expectedRoots[i]) > 1.0E-7)
			return false;
	return true;
};

TEST_CASE("Solve4 throws an exception if a = 0")
{
	CHECK_THROWS_AS(Solve4(0, 1, 1, 1, 1), std::invalid_argument);
};

TEST_CASE("Solve3 returns correct real roots")
{
	CHECK(SolutionIsEqualToExpected(Solve3(1, 0, 0, 1), 1, { -1.0 }));
	CHECK(SolutionIsEqualToExpected(Solve3(1, 0, 0, -1), 1, { 1.0 }));
	CHECK(SolutionIsEqualToExpected(Solve3(-1, 1, 0, 0), 2, { 0.0, 1.0 }));
	CHECK(SolutionIsEqualToExpected(Solve3(5, -8, -8, 5), 3, { -1.0, 1.3 - sqrt(69) / 10.0, 1.3 + sqrt(69) / 10.0 }));
	CHECK(SolutionIsEqualToExpected(Solve3(2, -11, 12, 9), 2, { -0.5, 3.0 }));
};

TEST_CASE("Solve2 returns correct real roots")
{
	CHECK(SolutionIsEqualToExpected(Solve2(1, 0, -4), 2, { -2.0, 2.0 }));
	CHECK(SolutionIsEqualToExpected(Solve2(1, -4, 4), 1, { 2.0 }));
	CHECK(SolutionIsEqualToExpected(Solve2(1, 1, 4), 0, {}));
};

TEST_CASE("Solve4 returns correct real roots")
{
	CHECK(SolutionIsEqualToExpected(Solve4(3, 6, -123, -126, 1080), 4, { -6.0, -4.0, 3.0, 5.0 }));
	CHECK(SolutionIsEqualToExpected(Solve4(1, 0, -1, 0, 0), 3, { -1.0, 0.0, 1.0 }));
	CHECK(SolutionIsEqualToExpected(Solve4(1, 3, 3, -1, -6), 2, { -2.0, 1.0 }));
	CHECK(SolutionIsEqualToExpected(Solve4(1, 0, 0, 0, 0), 1, { 0.0 }));
};

TEST_CASE("Solve4 throws exception if no real roots")
{
	CHECK_THROWS_AS(Solve4(1, 1, 1, 1, 1), std::domain_error);
	CHECK_THROWS_AS(Solve4(16, 0, 145, 0, 9), std::domain_error);
};
