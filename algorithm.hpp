#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>

void swap(int&, int&);

int linear(std::vector<int>, int, int);

int binaryLeft(std::vector<int>, int, int, int);

int binaryRight(std::vector<int>, int, int, int);

int min(std::vector<int>, int);

int max(std::vector<int>, int);

void bubbleSort(std::vector<int>, int);

std::vector<int> bubbleSort(std::vector<int>, int, bool);

std::vector<int> insertionSort(std::vector<int>, int, bool);

std::vector<int> selectionSort(std::vector<int>, int, bool);

void merge(std::vector<int>&, int, int, int, bool);

void mergeSort(std::vector<int>&, int, int, int, bool);

void permute(std::vector<std::vector<int>>&, std::vector<int>, std::vector<int>, std::vector<bool>);

std::vector<std::vector<int>> permutation(std::vector<int>);

#endif
