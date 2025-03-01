#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include <vector>

template <typename T>
using vector2d = std::vector<std::vector<T>>;

std::vector<float> gaussianElimination(int, vector2d<float>, std::vector<float>);

std::vector<float> gaussJordanElimination(int, vector2d<float>, std::vector<float>);

vector2d<float> rowEchelon(int, int, vector2d<float>);

vector2d<float> reducedRowEchelon(int, int, vector2d<float>);

int rank(int, int, vector2d<float>);

vector2d<float> matrixAdd(int, int, vector2d<float>, vector2d<float>);

vector2d<float> scalarMultiplication(int, int, vector2d<float>, float);

vector2d<float> transpose(int rows, int columns, vector2d<float> matrix);

int isSymmetric(int, vector2d<float>);

vector2d<float> matrixMultiply(int, int, int, vector2d<float>, vector2d<float>);

vector2d<float> matrixInverse(int, vector2d<float>);

void rankNormal(int, int, vector2d<float>);

float determinant(int, vector2d<float>);

#endif
