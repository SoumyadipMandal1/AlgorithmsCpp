#ifndef MATH_H
#define MATH_H
#endif

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);

	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int horner(int arr[], int x, int length)
{
	// If an array [a0, a1, a2, ..., an] is given, then
	// a0 + a1 * x + a2 * x^2 + ... + an * x^n is returned
	// a0 + x * (a1 + x* (a2 + ... + x * (an-1 + x * an)))

	int result = 0;

	for (int i = length - 1; i >= 0; i--)
		result = arr[i] + result * x;

	return result;
}
