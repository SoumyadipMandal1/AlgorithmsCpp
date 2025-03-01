#include <iostream>
#include <vector>
#include "linearAlgebra.hpp"

std::vector<float> gaussianElimination(int size, vector2d<float> coefficient, std::vector<float> augmented)
{
	// Solve a linear equation using Gaussian Elimination.
	// Coefficient matrix is of size n x n and augmented vector is of size n
	float scalingFactor, sum;

	// Converts the matrix to row echelon form

	// Iterates through each row
	for (int i = 0; i < size; i++)
	{
		// For handling zero divisions
		if (coefficient[i][i] == 0)
		{
			// Checks if any other row below has a non-zero pivot
			int nonZeroChecker = 0;
			for (int j = i + 1; j < size; j++)
			{
				if (coefficient[j][i])
				{
					nonZeroChecker = 1;
					// temp is used here to interchange each non-zero element in the two rows
					std::swap(coefficient[i], coefficient[j]);

					// Interchanges the element in augmented matrix
					std::swap(augmented[i], augmented[j]);
					break;
				}
			}

			if (!nonZeroChecker)
			{
				std::cout << "The system of linear equations has no solutions\n";
				return {};
			}
		}

		// Executing necessary elementary roe operations
		for (int j = i + 1; j < size; j++)
		{
			// If scalingFactor is zero, then there will be no changes
			if (coefficient[j][i] == 0)
				continue;

			// Elemetary row operations are done in such a way that
			// all the numbers in the matrix below the pivot becomes zero
			scalingFactor = coefficient[j][i] / coefficient[i][i];
			coefficient[j][i] = 0;
			for (int k = i + 1; k < size; k++)
				coefficient[j][k] -= coefficient[i][k] * scalingFactor;
			augmented[j] -= augmented[i] * scalingFactor;
		}
	}

	// Calculating the result by back substitution
	// sum is used here
	for (int i = size - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j < size; j++)
			sum += coefficient[i][j] * augmented[j];
		augmented[i] = (augmented[i] - sum) / coefficient[i][i];
	}

	return augmented;
}

std::vector<float> gaussJordanElimination(int size, vector2d<float> coefficient, std::vector<float> augmented)
{
	// Solve a linear equation using Gaussian - Jordan Elimination.
	// Coefficient matrix is of size n x n and augmented vector is of size n
	float scalingFactor;

	// Converts the matrix to row echelon form

	// Iterates through each row
	for (int i = 0; i < size; i++)
	{
		// For handling zero divisions
		if (coefficient[i][i] == 0)
		{
			// Checks if any other row below has a non-zero pivot
			int nonZeroChecker = 0;
			for (int j = i + 1; j < size; j++)
			{
				// temp is used here
				if (coefficient[j][i])
				{
					nonZeroChecker = 1;
					// temp is used here to interchange each non-zero element in the two rows
					std::swap(coefficient[i], coefficient[j]);

					// Interchanges the element in augmented matrix
					std::swap(augmented[i], augmented[j]);
					break;
				}
			}

			if (!nonZeroChecker)
			{
				std::cout << "The system of linear equations has no solutions\n";
				return {};
			}
		}

		// scalingFactor is used here to convert the pivot to 1 and
		// the subsequent row so that the system remain equivalent
		scalingFactor = coefficient[i][i];
		coefficient[i][i] = 1;

		// Setting the pivot to 1
		for (int j = i + 1; j < size; j++)
			coefficient[i][j] /= scalingFactor;
		augmented[i] /= scalingFactor;

		// Computing the result
		// scalingFactor is used here to make all the rows other than
		// the pivotal row to zero
		for (int k = 0; k < size; k++)
		{
			if (k != i)
			{
				scalingFactor = coefficient[k][i];
				for (int j = i; j < size; j++)
					coefficient[k][j] -= scalingFactor * coefficient[i][j];
				augmented[k] -= scalingFactor * augmented[i];
			}
		}
	}

	return augmented;
}

vector2d<float> rowEchelon(int rows, int columns, vector2d<float> matrix)
{
    // Converts a matrix into row echelon form
	int row, column;
    float scalingFactor;

    // Checking for non-zero pivot and interchanging rows
    // if a non-zero number is spotted below a zero

	// Keeps track of rows and columns
	row = column = 0;

	// This flag checks whether to increment column only or not
	int columnOnlyIncrement;

	// This loop stops operating if one of variable exceeds in value
	while (row < rows && column < columns)
	{
		// Initializing the flag
		columnOnlyIncrement = 0;

		// If the number bottom - right of the pivot is not zero
		if (matrix[row][column] == 0)
		{
			// Flag will be set to zero if all the numbers below the pivot is zero
			columnOnlyIncrement = 1;

			// Checks if a number below the pivot is non-zero
			for (int i = row + 1; i < rows; i++)
			{
				if (matrix[i][column])
				{
					// Changing the flag if a non zero element is found below the pivot
					columnOnlyIncrement = 0;

					// Swapping the two rows and then, breaking the loop
					std::swap(matrix[row], matrix[i]);
					break;
				}
			}
		}

		// If both column and row is to be incremented
		if (!columnOnlyIncrement)
		{
			// scalingFactor is used here
			// Iterates through each row
			for (int i = row + 1; i < rows; i++)
			{
				// If scalingFactor is zero, then there will be no changes
				if (matrix[i][column] == 0)
					continue;

				scalingFactor = matrix[i][column] / matrix[row][column];
				// Each number below the pivot should be zero
				matrix[i][column] = 0;

				// Iterates through each column
				for (int j = column + 1; j < columns; j++)
				{
					matrix[i][j] -= matrix[row][j] * scalingFactor;
				}
			}

			// Incrementing row and column if necessary operation is over
			row++;
			column++;
		}

		// If only column is to be incremented
		else
		{
			// Incrementing column if all the numbers below and including pivot is zero
			column++;
			continue;
		}
	}

	return matrix;
}

vector2d<float> reducedRowEchelon(int rows, int columns, vector2d<float> matrix)
{
    // Converts a matrix into row echelon form
	int row, column;
    float temp, scalingFactor;

    // Checking for non-zero pivot and interchanging
    // rows if a non-zero number is spotted below a zero

	// Keeps track of rows and columns
	row = column = 0;

	// This flag checks whether to increment column only or not
	int columnOnlyIncrement;

	// This loop stops operating if one of variable exceeds in value
	while (row < rows && column < columns)
	{
		// Initializing the flag
		columnOnlyIncrement = 0;

		// If the number bottom - right of the pivot is not zero
		if (matrix[row][column] == 0)
		{
			// Flag will be set to zero if all the numbers below the pivot is zero
			columnOnlyIncrement = 1;

			for (int i = row + 1; i < rows; i++)
			{
				if (matrix[i][column])
				{
					// Changing the flag if a non zero element is found below the pivot
					columnOnlyIncrement = 0;

					// Swapping the two rows and then, breaking the loop
					std::swap(matrix[row], matrix[i]);
					break;
				}
			}
		}

		if (!columnOnlyIncrement)
		{

			// Scaling the pivot to 1
			scalingFactor = matrix[row][column];
			matrix[row][column] = 1;

			// Scaling the row so that pivot = 1
			for (int i = column + 1; i < columns; i++)
				matrix[row][i] /= scalingFactor;

			// scalingFactor is used here
			for (int i = 0; i < rows; i++)
			{
				// All the numbers above and below the pivot changed to zero
				// by Elemetary row operations
				if (i != row)
				{
					// If scalingFactor is zero, then there will be no changes
					if (matrix[i][column] == 0)
						continue;

					scalingFactor = matrix[i][column];
					matrix[i][column] = 0;
					for (int j = column + 1; j < columns; j++)
						matrix[i][j] -= matrix[row][j] * scalingFactor;
				}
			}

			// Incrementing row and column if necessary operation is over
			row++;
			column++;
		}
		else
		{
			// Incrementing column if all the numbers below and including pivot is zero
			column++;
			continue;
		}
	}

	return matrix;
}

int rank(int rows, int columns, vector2d<float> matrix)
{
	// Rank is the number of nonzero rows in row echelon form or row reduced echelon form

	// This flag checks if the row is non - zero or not
	int flag;

	// Initializing the rank variable
	int rank = 0;

	// Converting the matrix to row reduced echelon form
	matrix = rowEchelon(rows, columns, matrix);

	// Iterating through each row
	for (int i = 0; i < rows; i++)
	{
		flag = 0;

		// Checking each number of each row
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j])
				flag = 1;
		}

		// If the row is non - zero, then incrementing the rank variable
		if (flag)
			rank++;

		// All the rows below a zero row are zero rows
		// Thus no need to continue the loop further
		else
 ;			break;
	}

	return rank;
}

vector2d<float> matrixAdd(int rows, int columns, vector2d<float> matrix1, vector2d<float> matrix2)
{
	vector2d<float> matrixSum;

	// Adding matrix
	// Looping the rows
	for (int i = 0; i < rows; i++)
	{
		// Looping the columns
		for (int j = 0; j < columns; j++)
			matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
	}

	return matrixSum;
}

vector2d<float> scalarMultiplication(int rows, int columns, vector2d<float> matrix, float scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] *= scalar;
	}

	return matrix;
}

vector2d<float> transpose(int rows, int columns, vector2d<float> matrix)
{
	vector2d<float> matrixTranspose;

	// Transposing matrix
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
			matrixTranspose[i][j] = matrix[j][i];
	}

	return matrixTranspose;
}

int isSymmetric(int size, vector2d<float> matrix)
{
	// Transposing Matrix
	vector2d<float> matrixTranspose;
	matrixTranspose = transpose(size, size, matrix);

	// Stores the condition whether a matrix is symmetric or not
	int flag = 1;

	// Checks if each number in each position is same or not
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] != matrixTranspose[i][j])
			{
				flag = 0;
				break;
			}

			if (!flag)
				break;
		}
	}

	return flag;
}

vector2d<float> matrixMultiply(int m, int p, int n, vector2d<float> matrix1, vector2d<float> matrix2)
{
	// uses the old O(n^3) algorithm
	vector2d<float> matrixProduct;

	// Multiplying matrices
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixProduct[i][j] = 0;
			for (int k = 0; k < p; k++)
				matrixProduct[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}

	return matrixProduct;
}

vector2d<float> matrixInverse(int size, vector2d<float> matrix)
{
	// Inversing a matrix
	float temp, scalingFactor;

	// Creating Identity Matrix
	vector2d<float> identity;

	for (int i = 0; i < size; i++)
	{
		// Initializing every element in the matrix to zero
		for (int j = 0; j < size; j++)
			identity[i][j] = 0;

		// Only diagonal element equals to one
		identity[i][i] = 1;
	}

	// Creating an inverse matrix by converting the matrix into its
	// reduced row echelon form and applying the same elementary matrix operations
	// on the identity matrix
	for (int i = 0; i < size; i++)
	{
		// If the pivot is zero
		if (matrix[i][i] == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				// temp is used here
				if (matrix[i][j])
				{
					for (int k = 0; k < size; k++)
					{
						// Swapping rows of the matrix
						std::swap(matrix[i], matrix[j]);

						// Swapping rows of Identity matrix
						std::swap(identity[i], identity[j]);
					}
					break;
				}
			}
		}

		// scalingFactor is used here to convert the pivot to 1
		scalingFactor = matrix[i][i];
		matrix[i][i] = 1;

		// Scaling the matrix
		for (int j = i + 1; j < size; j++)
			matrix[i][j] /= scalingFactor;

		// Scaling the Identity matrix
		for (int j = 0; j < size; j++)
			identity[i][j] /= scalingFactor;

		// Computing the result
		// scalingFactor is used to convert all the rows other than the pivotal row
		// to zero and performing the same operations on the Identity matrix
		for (int j = 0; j < size; j++)
		{
			if (j != i)
			{
				scalingFactor = matrix[j][i];

				// On matrix
				matrix[j][i] = 0;
				for (int k = i + 1; k < size; k++)
					matrix[j][k] -= scalingFactor * matrix[i][k];

				// On Identity matrix
				for (int k = 0; k <= i; k++)
					identity[j][k] -= scalingFactor * identity[i][k];
			}
		}
	}

	return matrix;
}

void rankNormal(int rows, int columns, vector2d<float> matrix)
{
	int rankMatrix = rank(rows, columns, matrix);
	for (int i = 0; i < rankMatrix; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;
		matrix[i][i] = 1;
	}
	for (int i = rankMatrix; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;
	}
}


float determinant(int size, vector2d<float> matrix)
{
	int inversion = 0;
	int flag = 0;
	float scalingFactor, temp;
	float determinant = 1;

	for (int i = 0; i < size; i++)
	{
		// For handling zero divisions
		if (matrix[i][i] == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (matrix[j][i])
				{
					// temp is used here
					for (int k = 0; k < size; k++)
					{
						temp = matrix[i][k];
						matrix[i][k] = matrix[j][k];
						matrix[j][k] = temp;
					}
					inversion += 1;
					flag = 1;
				}
			}
		}

		if (flag)
		{
			return 0;
			break;
		}

		else
		{
			for (int j = i + 1; j < size; j++)
			{
				// If scalingFactor is zero, then there will be no changes
				if (matrix[j][i] == 0)
					continue;
				scalingFactor = matrix[j][i] / matrix[i][i];
				matrix[j][i] = 0;
				for (int k = i + 1; k < size; k++)
					matrix[j][k] -= matrix[i][k] * scalingFactor;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		determinant *= matrix[i][i];
	}

	if (inversion % 2) determinant *= -1;

	return determinant;
}
