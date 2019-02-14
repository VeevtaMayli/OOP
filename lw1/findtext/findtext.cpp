#include "pch.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> FindStringInStream(istream& in, string str)
{
	string tempStr;
	vector<int> stringNumbers;

	int stringNumber = 0;
	while (getline(in, tempStr))
	{
		stringNumber++;
		if (tempStr.find(str) != string::npos)
		{
			stringNumbers.push_back(stringNumber);
		}
	}

	return stringNumbers;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: findtext.exe <file name> <text to search>"
			 << endl;
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1]
			 << " for reading" << endl;
		return 1;
	}

	if (input.peek() == EOF)
	{
		cout << "Input file is empty" << endl;
		return 1;
	}

	string searchedStr = argv[2];

	if (searchedStr == "")
	{
		cout << "Text not found" << endl;
		return 1;
	}

	vector<int> foundedStringNumbers = FindStringInStream(input, searchedStr);

	if (!foundedStringNumbers.empty())
	{
		copy(foundedStringNumbers.begin(), foundedStringNumbers.end(), ostream_iterator<int>(cout, "\n"));
	}
	else
	{
		cout << "Text not found" << endl;
	}

	return 0;
}
