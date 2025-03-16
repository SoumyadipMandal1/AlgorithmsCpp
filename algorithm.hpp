#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>

void swap(int&, int&);

int linear(std::vector<int>, int, int);

int binaryLeft(std::vector<int>, int, int, int);

int binaryRight(std::vector<int>, int, int, int);

int min(std::vector<int>, int);

int max(std::vector<int>, int);

void permute(std::vector<std::vector<int>>&, std::vector<int>, std::vector<int>, std::vector<bool>);

std::vector<std::vector<int>> permutation(std::vector<int>);

#endif
