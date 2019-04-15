#include "pch.h"
#include "lw2/prime/prime.h"

using namespace std;

TEST_CASE("Test prime numbers set generation")
{
	PrimeSet test;

	// empty
	CHECK(GeneratePrimeNumbersSet(0) == test);

	// one prime number in range
	test = { 2 };
	CHECK(GeneratePrimeNumbersSet(2) == test);

	// some prime numbers in range
	test = { 2, 3, 5, 7, 11 };
	CHECK(GeneratePrimeNumbersSet(12) == test);

	CHECK(GeneratePrimeNumbersSet(1000).size() == 168);
	CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
}
