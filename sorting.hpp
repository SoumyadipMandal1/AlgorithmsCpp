#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

void bubbleSort(std::vector<int>, int);

std::vector<int> bubbleSort(std::vector<int>, int, bool);

std::vector<int> insertionSort(std::vector<int>, int, bool);

std::vector<int> selectionSort(std::vector<int>, int, bool);

void merge(std::vector<int> &, int, int, int, bool);

void mergeSort(std::vector<int> &, int, int, int, bool);

int partition(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr, int low, int high);

void heapify(std::vector<int> &arr, int index, int length);

void buildMaxHeap(std::vector<int> &arr);

void heapSort(std::vector<int> &arr);

#endif
