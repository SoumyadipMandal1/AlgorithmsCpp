#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#endif

void gaussianElimination(int size, float coefficient[size][size], float augmented[size])
{
	// Solve a linear equation using Gaussian Elimination

	// Converts the matrix to row echelon form
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
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
