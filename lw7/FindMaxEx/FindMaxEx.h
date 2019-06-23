#pragma once
#include <functional>
#include <vector>

template <typename T, typename Less>
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	auto maxIterator = arr.begin();
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (less(*maxIterator, *it))
		{
			maxIterator = it;
		}
	}

	maxValue = *maxIterator;
	return true;
}