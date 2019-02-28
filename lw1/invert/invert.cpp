#include "pch.h"
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

const int MATRIX_SIZE = 3;
const double EPS = 0.0001;

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

	for (size_t row = 0; row < MATRIX_SIZE; row++)
	{
		for (size_t col = 0; col < MATRIX_SIZE; col++)
		{
			if (input.eof())
			{
				cout << "There is not 3x3 matrix in " << filePath << endl;
				return false;
			}
			input >> matrix[row][col];
		}
	}
	return true;
}

double GetSubdeterminant(const Matrix& matrix, const size_t row, const size_t col)
{
	array<double, 4> minorElements;
	size_t currElement = 0;

	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		if (i == row)
		{
			continue;
		}
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			if (j == col)
			{
				continue;
			}
			minorElements[currElement] = matrix[i][j];
			currElement++;
		}
	}
	return minorElements[0] * minorElements[3] - minorElements[1] * minorElements[2];
}

double GetDeterminant(const Matrix& matrix)
{
	double determinant = 0;
	const size_t row = 0;
	short sign = 1;

	for (size_t col = 0; col < MATRIX_SIZE; col++)
	{
		determinant += sign * matrix[row][col] * GetSubdeterminant(matrix, row, col);
		sign *= -1;
	}
	return determinant;
}

bool TryToInvertMatrix(const Matrix& matrix, Matrix& invertedMatrix)
{
	double determinant = GetDeterminant(matrix);
	if (fabs(determinant - 0) < EPS)
	{
		cout << "The determinant of the matrix is 0 so the inverse matrix does not exist" << endl;
		return false;
	}

	short sign = 1;
	for (size_t row = 0; row < MATRIX_SIZE; row++)
	{
		for (size_t col = 0; col < MATRIX_SIZE; col++)
		{
			invertedMatrix[col][row] = sign * GetSubdeterminant(matrix, row, col) / determinant;
			sign *= -1;
		}
	}
	return true;
}

void PrintMatrix(const Matrix& matrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			cout << fixed << setprecision(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
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

	Matrix invertedMatrix;

	if (!TryToInvertMatrix(inputMatrix, invertedMatrix))
	{
		return 1;
	}

	PrintMatrix(invertedMatrix);
	return 0;
}
