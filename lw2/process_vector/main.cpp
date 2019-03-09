#include "pch.h"
#include "process_vector.h"

using namespace std;

int main()
{
	vector<double> inputVector(istream_iterator<double>(cin), (istream_iterator<double>()));

	ProcessVector(inputVector);
	sort(inputVector.begin(), inputVector.end());
	PrintVector(inputVector);
	return 0;
}
