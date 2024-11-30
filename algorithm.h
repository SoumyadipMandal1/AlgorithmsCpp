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

int linear(int arr[], int length, int key)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == key)
			return i;
	}
}

int binaryLeft(int arr[], int low, int high, int key)
{
	// Calculating the middle value
	int mid = low + (high - low) / 2;

	if (arr[mid] == key)
	{
		// arr[low - 1] is out of range
		if (mid == low)
			return mid;
		// Checking if any other element in the left is equal to the key
		else if (arr[mid - 1] == key)
			return binaryLeft(arr, low, mid, key);
		else
			return mid;
	}

	// If key is not found
	else if (mid == low || mid == high)
		return -1;

	else if (arr[mid] > key)
		return binaryLeft(arr, low, mid, key);
	else
		return binaryLeft(arr, mid, high, key);
}

int binaryRight(int arr[], int low, int high, int key)
{
	// Calculating the middle value
	int mid = low + (high - low) / 2;

	if (arr[mid] == key)
	{
		// arr[high + 1] is out of range
		if (mid == high)
			return mid;
		// Checking if any other element in right is equal to the key
		else if (arr[mid + 1] == key)
			// if low = high - 1, then
			// mid = (high - 1) - (high - (high - 1)) / 2
			// mid = high - 1 - (high - high + 1) / 2
			// mid = high - 1 - 1/2 = high - 1
			// mid = low
			// To fix this issue, mid + 1 is taken instead of mid
			// as done in binarySearchLeft
			return binaryRight(arr, mid + 1, high, key);
		else
			return mid;
	}

	// If key is not found
	else if (mid == low || mid == high)
		return -1;

	else if (arr[mid] > key)
		return binaryRight(arr, low, mid, key);
	else
		return binaryRight(arr, mid, high, key);
}

void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}

}

void bubbleSortReverse(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void insertionSort(int arr[], int length)
{
	int key, j; // For Loop optimization
	for (int i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void insertionSortReverse(int arr[], int length)
{
	int key, j; // For loop optimization
	for (int i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
