﻿#include "pch.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> FindStringInStream(istream& in, const string str)
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

vector<int> FindStringInFile(const string filePath, const string str, bool& err)
{
	ifstream input(filePath);

	if (!input.is_open())
	{
		cout << "Failed to open " << filePath
			 << " for reading" << endl;
		err = true;
		return {};
	}
	return FindStringInStream(input, str);
}

int main(int argc, char* argv[])
{
	bool err = false;

	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: findtext.exe <file name> <text to search>"
			 << endl;
		return 1;
	}

	string searchedStr = argv[2];

	vector<int> foundStringNumbers = FindStringInFile(argv[1], searchedStr, err);
	if (err)
		return 1;

	if (searchedStr == "")
		foundStringNumbers.clear();

	if (!foundStringNumbers.empty())
	{
		copy(foundStringNumbers.begin(), foundStringNumbers.end(), ostream_iterator<int>(cout, "\n"));
	}
	else
	{
		cout << "Text not found" << endl;
	}

	return 0;
}
