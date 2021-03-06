#include "stdafx.h"

const unsigned matrixSize = 3;
typedef std::array<std::array<float, matrixSize>, matrixSize> Matrix;

bool ReadMatrix(std::istream& inputFile, Matrix& matrix)
{
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			if (!(inputFile >> matrix[i][j]))
			{
				return false;
			}
		}
	}
	return true;
}

float FindDeterminant(const Matrix& inputMatrix)
{
	return inputMatrix[0][0] * inputMatrix[1][1] * inputMatrix[2][2]
		 + inputMatrix[0][1] * inputMatrix[1][2] * inputMatrix[2][0]
		 + inputMatrix[1][0] * inputMatrix[2][1] * inputMatrix[0][2]
		 - inputMatrix[0][2] * inputMatrix[1][1] * inputMatrix[2][0]
		 - inputMatrix[0][1] * inputMatrix[1][0] * inputMatrix[2][2]
		 - inputMatrix[1][2] * inputMatrix[2][1] * inputMatrix[0][0];
}

bool InvertMatrix(const Matrix& inputMatrix, Matrix& invertedMatrix)
{
	const float determinant = FindDeterminant(inputMatrix);

	if (fabs(determinant) <  0.0000001)
		return false;

	invertedMatrix[0][0] = (inputMatrix[1][1] * inputMatrix[2][2]
						   -inputMatrix[1][2] * inputMatrix[2][1]) / determinant;

	invertedMatrix[1][0] = -1 * (inputMatrix[1][0] * inputMatrix[2][2]
							   - inputMatrix[1][2] * inputMatrix[2][0]) / determinant;

	invertedMatrix[2][0] = (inputMatrix[1][0] * inputMatrix[2][1]
						  - inputMatrix[1][1] * inputMatrix[2][0]) / determinant;

	invertedMatrix[0][1] = -1 * (inputMatrix[0][1] * inputMatrix[2][2]
							   - inputMatrix[0][2] * inputMatrix[2][1]) / determinant;

	invertedMatrix[1][1] = (inputMatrix[0][0] * inputMatrix[2][2]
						  - inputMatrix[2][0] * inputMatrix[0][2]) / determinant;

	invertedMatrix[2][1] = -1 * (inputMatrix[0][0] * inputMatrix[2][1]
							   - inputMatrix[0][1] * inputMatrix[2][0]) / determinant;

	invertedMatrix[0][2] = (inputMatrix[0][1] * inputMatrix[1][2]
						  - inputMatrix[0][2] * inputMatrix[1][1]) / determinant;

	invertedMatrix[1][2] = -1 * (inputMatrix[0][0] * inputMatrix[1][2] 
							   - inputMatrix[0][2] * inputMatrix[1][0]) / determinant;

	invertedMatrix[2][2] = (inputMatrix[0][0] * inputMatrix[1][1] 
						  - inputMatrix[0][1] * inputMatrix[1][0]) / determinant;
	
	return true;
}

void PrintMatrix(const Matrix& invertedMatrix)
{
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			std::cout.precision(3);
			std::cout << invertedMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid argument count\n"
			<< "usage: invert.exe <inputMatrixFile>" << std::endl;
		return 1;
	}

	Matrix inputMatrix;
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	
	if (!inputFile)
	{
		std::cout << "File not found" << std::endl;
		return 1;
	}

	if (!ReadMatrix(inputFile, inputMatrix))
	{
		std::cout << "Could not read data from file" << std::endl;
		return 1;
	}

	Matrix invertedMatrix;

	if (!InvertMatrix(inputMatrix, invertedMatrix))
	{
		std::cout << "Determinant = 0. The inverse matrix does not exist" << std::endl;
		return 1;
	}

	PrintMatrix(invertedMatrix);
	
	return 0;
}