#include "pch.h"
#include "prime.h"

using namespace std;

const uint32_t MAX_UPPER_BOUND = 100000000;

bool ParseCommandLine(int argc, char* argv[], uint32_t& upperBound)
{
	if (argc != 2)
	{
		return false;
	}
	try
	{
		upperBound = stoul(argv[1]);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return false;
	}
	return upperBound <= MAX_UPPER_BOUND;
}

void PrintSet(const PrimeSet& s)
{
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
}

int main(int argc, char* argv[])
{
	uint32_t upperBound;
	if (!ParseCommandLine(argc, argv, upperBound))
	{
		cout << "Invalid upper bound of numbers. Correct value is less then " << MAX_UPPER_BOUND << endl;
		return 1;
	}
	PrintSet(GeneratePrimeNumbersSet(upperBound));
	return 0;
}
