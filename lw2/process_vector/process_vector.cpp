#include "pch.h"
#include "process_vector.h"

void ProcessVector(std::vector<double>& v)
{
	if (v.size() != 0)
	{
		auto min = *min_element(v.begin(), v.end());
				
		for (auto& item : v)
		{
			item *= min;
		}
	}
}

void PrintVector(std::vector<double> const& v)
{
	copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
}
