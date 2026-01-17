#ifndef MATH_H
#define MATH_H

#include <vector>

void swap(int &, int &);

int gcd(int, int);

int optimized_gcd(int a, int b);

std::pair<int, std::pair<int, int>> extended_gcd(int a, int b);

int horner(std::vector<int>, int, int);

int factorial(int n);

int permutation(int n, int k);

int combination(int n, int k);

bool isPrime(int n);

#endif
