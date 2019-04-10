#include "pch.h"
#include "prime.h"

PrimeSet GeneratePrimeNumbersSet(int upperBound)
{
	PrimeSet primes;
	std::vector<bool> primeVector(upperBound + 1);
	std::fill(primeVector.begin(), primeVector.end(), true);

	if (upperBound >= 2)
	{
		primes.insert(2);
	}

	for (uint32_t i = 3; i <= upperBound; i += 2)
	{
		if (primeVector[i])
		{
			primes.insert(i);
			for (uint32_t j = i + i; j <= upperBound; j += i)
			{
				primeVector[j] = false;
			}
		}
	}
	return 
}
