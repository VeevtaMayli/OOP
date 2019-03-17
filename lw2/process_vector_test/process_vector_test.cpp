#include "pch.h"
#include "lw2/process_vector/process_vector.h"

TEST_CASE("ProcessVector() returns vector from argument multiplied by its minimum element")
{
	// empty vector
	std::vector<double> in = {};
	std::vector<double> out = {};
	ProcessVector(in);
	CHECK(in == out);

	// single element vector
	in = { 2 };
	out = { 4 };
	ProcessVector(in);
	CHECK(in == out);

	// negative vector
	in = { -1, 2, -3 };
	out = { 3, -6, 9 };
	ProcessVector(in);
	CHECK(in == out);

	// vector with 0
	in = { 3, 1, 0 };
	out = { 0, 0, 0 };
	ProcessVector(in);
	CHECK(in == out);
}
