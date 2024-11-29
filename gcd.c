#include <stdio.h>

void swap(int* a, int* b)
{
	// Swapping two integers
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b)
{
	if (b > a) swap(&a, &b);
	if (b == 0) return a;   // base case
	else return gcd(b, a % b);
}

int main()
{
	int a, b;               // Initializing variables
	scanf("%d%d", &a, &b);  // Taking input
	printf("%d\n", gcd(a, b)); // Printing output
}

