#ifndef ALGORITHM_H
#define ALGORITHM_H
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

int linearSearch(int arr[], int length, int key)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == key)
			return i;
	}
}
