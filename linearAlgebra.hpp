#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include <vector>

template <typename T> using vector2d = std::vector<std::vector<T>>;

float absolute(float);

std::vector<float> gaussianElimination(vector2d<float>, std::vector<float>);

std::vector<float> gaussJordanElimination(vector2d<float>, std::vector<float>);

std::vector<float> gaussianElimination_partialPivoting(vector2d<float>, std::vector<float>);

std::vector<float> gaussianElimination_completePivoting(vector2d<float>, std::vector<float>);

vector2d<float> rowEchelon(vector2d<float>);

vector2d<float> reducedRowEchelon(vector2d<float>);

int rank(vector2d<float>);

vector2d<float> matrixAdd(vector2d<float>, vector2d<float>);

vector2d<float> scalarMultiplication(vector2d<float>, float);

vector2d<float> transpose(vector2d<float> matrix);

int isSymmetric(vector2d<float>);

vector2d<float> matrixMultiply(vector2d<float>, vector2d<float>);

vector2d<float> matrixInverse(vector2d<float>);

void rankNormal(vector2d<float>);

float determinant(vector2d<float>);

#endif
