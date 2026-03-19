#include "linearAlgebra.hpp"
#include <stdexcept>
#include <vector>

int maximum(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int next_power_of_2(int n)
{
    // Find the smallest power of 2 greater than or equal to n

    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}

vector2d<float> fill_zeros(int size, vector2d<float> matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    // Returns a matrix of dimension size x size such that
    // size is greater than equal to number of rows and columns
    // and fils the new indexes with zero

    vector2d<float> result(size, std::vector<float>(size));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i < rows && j < columns)
                result[i][j] = matrix[i][j];
            else
                result[i][j] = 0;
        }
    }
    return result;
}

void split_matrix(int size, vector2d<float> &matrix, vector2d<float> &matrix11, vector2d<float> &matrix12,
                  vector2d<float> &matrix21, vector2d<float> &matrix22)
{
    // splitting matrix of size 2n x 2n
    // into four matrices of size n x n

    int new_size = size / 2;
    for (int i = 0; i < new_size; i++)
    {
        for (int j = 0; j < new_size; j++)
        {
            matrix11[i][j] = matrix[i][j];
            matrix12[i][j] = matrix[i][j + new_size];
            matrix21[i][j] = matrix[i + new_size][j];
            matrix22[i][j] = matrix[i + new_size][j + new_size];
        }
    }
}

void join_matrix(int size, vector2d<float> &matrix, vector2d<float> &matrix11, vector2d<float> &matrix12,
                 vector2d<float> &matrix21, vector2d<float> &matrix22)
{
    // Joining four matrices of size n x n
    // into a new matrix of size 2n x 2n

    int new_size = size / 2;
    for (int i = 0; i < new_size; i++)
    {
        for (int j = 0; j < new_size; j++)
        {
            matrix[i][j] = matrix11[i][j];
            matrix[i][j + new_size] = matrix12[i][j];
            matrix[i + new_size][j] = matrix21[i][j];
            matrix[i + new_size][j + new_size] = matrix22[i][j];
        }
    }
}

vector2d<float> strassen(int size, vector2d<float> A, vector2d<float> B)
{
    if (size == 1)
        return {{A[0][0] * B[0][0]}};

    int new_size = size / 2;

    vector2d<float> C(size, std::vector<float>(size));

    vector2d<float> A11(new_size, std::vector<float>(new_size));
    vector2d<float> A12(new_size, std::vector<float>(new_size));
    vector2d<float> A21(new_size, std::vector<float>(new_size));
    vector2d<float> A22(new_size, std::vector<float>(new_size));

    vector2d<float> B11(new_size, std::vector<float>(new_size));
    vector2d<float> B12(new_size, std::vector<float>(new_size));
    vector2d<float> B21(new_size, std::vector<float>(new_size));
    vector2d<float> B22(new_size, std::vector<float>(new_size));

    split_matrix(size, A, A11, A12, A21, A22);
    split_matrix(size, B, B11, B12, B21, B22);

    vector2d<float> P1 = strassen(new_size, A11, matrixSubtract(B12, B22));
    vector2d<float> P2 = strassen(new_size, matrixAdd(A11, A12), B22);
    vector2d<float> P3 = strassen(new_size, matrixAdd(A21, A22), B11);
    vector2d<float> P4 = strassen(new_size, A22, matrixSubtract(B21, B11));
    vector2d<float> P5 = strassen(new_size, matrixAdd(A11, A22), matrixAdd(B11, B22));
    vector2d<float> P6 = strassen(new_size, matrixSubtract(A12, A22), matrixAdd(B21, B22));
    vector2d<float> P7 = strassen(new_size, matrixSubtract(A11, A21), matrixAdd(B11, B12));

    vector2d<float> C11 = matrixAdd(matrixSubtract(matrixAdd(P5, P4), P2), P6);
    vector2d<float> C12 = matrixAdd(P1, P2);
    vector2d<float> C21 = matrixAdd(P3, P4);
    vector2d<float> C22 = matrixSubtract(matrixSubtract(matrixAdd(P5, P1), P3), P7);

    join_matrix(size, C, C11, C12, C21, C22);

    return C;
}

vector2d<float> matrix_multiply(vector2d<float> matrixA, vector2d<float> matrixB)
{
    // Checking the size of the matrices
    int m, p, n;
    if (matrixA[0].size() != matrixB.size())
        throw std::logic_error("Number of columns in the first matrix should be equal to the number of columns in the "
                               "second matrix in matrix multiplication:");
    else
    {
        m = matrixA.size();
        p = matrixB.size();
        n = matrixB[0].size();
    }

    int size = next_power_of_2(maximum(maximum(m, p), n));
    vector2d<float> A = fill_zeros(size, matrixA);
    vector2d<float> B = fill_zeros(size, matrixB);

    vector2d<float> matrixC = strassen(size, A, B);

    vector2d<float> result(m, std::vector<float>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
            result[i][j] = matrixC[i][j];
    }
    return result;
}
