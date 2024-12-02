#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#endif

void gaussianElimination(int size, float coefficient[size][size], float augmented[size])
{
	// Solve a linear equation using Gaussian Elimination.
	// Coefficient matrix is of size n x n and augmented vector is of size n

	// Converts the matrix to row echelon form
	for (int i = 0; i < size; i++)
	{
		// For handling zero divisions
		if (coefficient[i][i] == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (coefficient[j][i])
				{
					float temp;
					for (int k = 0; k < size; k++)
					{
						temp = coefficient[i][k];
						coefficient[i][k] = coefficient[j][k];
						coefficient[j][k] = temp;
					}
					temp = augmented[i];
					augmented[i] = augmented[j];
					augmented[j] = temp;
					break;
				}
			}
		}

		for (int j = i + 1; j < size; j++)
		{
			// If multiplyingFactor is zero, then there will be no changes
			if (coefficient[j][i] == 0)
				continue;
			float multiplyingFactor = coefficient[j][i] / coefficient[i][i];
			coefficient[j][i] = 0;
			for (int k = i + 1; k < size; k++)
				coefficient[j][k] -= coefficient[i][k] * multiplyingFactor;
			augmented[j] -= augmented[i] * multiplyingFactor;
		}
	}

	// Calculating the result by back substitution
	float sum;
	for (int i = size - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j < size; j++)
			sum += coefficient[i][j] * augmented[j];
		augmented[i] = (augmented[i] - sum) / coefficient[i][i];
	}
}

void gaussJordanElimination(int size, float coefficient[size][size], float augmented[size])
{
	// Solve a linear equation using Gaussian - Jordan Elimination.
	// Coefficient matrix is of size n x n and augmented vector is of size n

	// Converts the matrix to row echelon form
	for (int i = 0; i < size; i++)
	{
		// For handling zero divisions
		if (coefficient[i][i] == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (coefficient[j][i])
				{
					float temp;
					for (int k = 0; k < size; k++)
					{
						temp = coefficient[i][k];
						coefficient[i][k] = coefficient[j][k];
						coefficient[j][k] = temp;
					}
					temp = augmented[i];
					augmented[i] = augmented[j];
					augmented[j] = temp;
					break;
				}
			}
		}

		float dividingFactor = coefficient[i][i];
		coefficient[i][i] = 1;

		// Setting the pivot to 1
		for (int j = i + 1; j < size; j++)
			coefficient[i][j] /= dividingFactor;
		augmented[i] /= dividingFactor;

		// Computing the result
		float multiplyingFactor;
		for (int k = 0; k < size; k++)
		{
			if (k != i)
			{
				multiplyingFactor = coefficient[k][i];
				for (int j = i; j < size; j++)
					coefficient[k][j] -= multiplyingFactor * coefficient[i][j];
				augmented[k] -= multiplyingFactor * augmented[i];
			}
		}
	}
}
