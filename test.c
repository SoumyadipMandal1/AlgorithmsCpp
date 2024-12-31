#include "linearAlgebra.h"
#include <stdio.h>

int main()
{
	float matrix[2][2] = {{2, 1},
							{1, 2}};
	/**float matrix2[4][3] = {{4, -3, 4},
							{2, -14, -3},
							{-2, 14, 0},
							{1, -7, 15}};**/
	printf("%f\n", determinant(2, matrix));
}
