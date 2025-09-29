#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>

void swap(int &, int &);

template <typename T> inline std::vector<T> array_push(std::vector<T> array, T parameter)
{
    array.push_back(parameter);
    return array;
}

int linear(std::vector<int>, int, int);

int binaryLeft(std::vector<int>, int, int, int);

int binaryRight(std::vector<int>, int, int, int);

int interpolationSearch(std::vector<int>, int, int, int);

int min(std::vector<int>);

int minpair(int, int);

int max(std::vector<int>);

int maxpair(int, int);

void permute(std::vector<std::vector<int>> &, std::vector<int>, std::vector<int>, std::vector<bool>);

std::vector<std::vector<int>> permutation(std::vector<int>);

int partiton5(std::vector<int> &, int, int);

int pivot(std::vector<int> &, int, int);

int partition(std::vector<int> &, int, int, int, int);

int select(std::vector<int> &, int, int, int);

int nthSmallest(std::vector<int> &, int);

#endif
