#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#endif

void gaussianElimination(int size, float coefficient[size][size], float augmented[size])
{
	// Solve a linear equation using Gaussian Elimination

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
			// If alpha is zero, then there will be no changes
			if (coefficient[j][i] == 0)
				continue;
			float alpha = coefficient[j][i] / coefficient[i][i];
			coefficient[j][i] = 0;
			for (int k = i + 1; k < size; k++)
				coefficient[j][k] -= coefficient[i][k] * alpha;
			augmented[j] -= augmented[i] * alpha;
		}
	}

	float sum;
	for (int i = size - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j < size; j++)
			sum += coefficient[i][j] * augmented[j];
		augmented[i] = (augmented[i] - sum) / coefficient[i][i];
	}
}
