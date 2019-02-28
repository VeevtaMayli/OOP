#include "pch.h"
#include <array>
#include <fstream>
#include <iostream>
#include <string>

const int MATRIX_SIZE = 3;

using namespace std;

typedef array<array<double, MATRIX_SIZE>, MATRIX_SIZE> Matrix;

bool TryToReadMatrixFromFile(string filePath, Matrix& matrix)
{
	ifstream input(filePath);
	if (!input.is_open())
	{
		cout << "Failed to open " << filePath << " for reading";
		return false;
	}

	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			if (input.eof())
			{
				cout << "There is not 3x3 matrix in " << filePath << endl;
				return false;
			}
			input >> matrix[i][j]; 
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: invert.exe <matrix file>"
			 << endl;
		return 1;
	}

	Matrix inputMatrix;

	if (!TryToReadMatrixFromFile(argv[1], inputMatrix))
	{
		return 1;
	}
	
}
