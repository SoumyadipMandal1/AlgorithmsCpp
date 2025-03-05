#include <vector>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int linear(std::vector<int> array, int length, int key)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == key)
			return i;
	}

	// If key is not found in the array
	return -1;
}

int binaryLeft(std::vector<int> array, int low, int high, int key)
{
	// Calculating the middle value
	int mid = low + (high - low) / 2;

	if (array[mid] == key)
	{
		// array[low - 1] is out of range
		if (mid == low)
			return mid;
		// Checking if any other element in the left is equal to the key
		else if (array[mid - 1] == key)
			return binaryLeft(array, low, mid, key);
		else
			return mid;
	}

	// If key is not found
	else if (mid == low || mid == high)
		return -1;

	else if (array[mid] > key)
		return binaryLeft(array, low, mid, key);
	else
		return binaryLeft(array, mid, high, key);
}

int binaryRight(std::vector<int> array, int low, int high, int key)
{
	// Calculating the middle value
	int mid = low + (high - low) / 2;

	if (array[mid] == key)
	{
		// array[high + 1] is out of range
		if (mid == high)
			return mid;
		// Checking if any other element in right is equal to the key
		else if (array[mid + 1] == key)
			// if low = high - 1, then
			// mid = (high - 1) - (high - (high - 1)) / 2
			// mid = high - 1 - (high - high + 1) / 2
			// mid = high - 1 - 1/2 = high - 1
			// mid = low
			// To fix this issue, mid + 1 is taken instead of mid
			// as done in binarySearchLeft
			return binaryRight(array, mid + 1, high, key);
		else
			return mid;
	}

	// If key is not found
	else if (mid == low || mid == high)
		return -1;

	else if (array[mid] > key)
		return binaryRight(array, low, mid, key);
	else
		return binaryRight(array, mid, high, key);
}

int min(std::vector<int> array, int length)
{
	int min = array[0];
	for (int i = 1; i < length; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return min;
}

int max(std::vector<int> array, int length)
{
	int max = array[0];
	for (int i = 1; i < length; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return max;
}

std::vector<int> bubbleSort(std::vector<int> array, int length, bool reverse = false)
{
	if (reverse)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (array[i] < array[j])
					swap(array[i], array[j]);
			}
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (array[i] > array[j])
					swap(array[i], array[j]);
			}
		}
	}

	return array;
}

std::vector<int> insertionSort(std::vector<int> array, int length, bool reverse = false)
{
	int key, j; // For Loop optimization

	if (reverse)
	{
		int key, j; // For Loop optimization
		for (int i = 1; i < length; i++)
		{
			key = array[i];
			j = i - 1;
			while (j >= 0 && array[j] < key)
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = key;
		}
	}
	else
	{
		for (int i = 1; i < length; i++)
		{
			key = array[i];
			j = i - 1;
			while (j >= 0 && array[j] > key)
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = key;
		}
	}

	return array;
}

std::vector<int> selectionSort(std::vector<int> array, int length, bool reverse = false)
{
	if (reverse)
	{
		int min, minpos; // For loop optimization
		for (int i = 0; i < length - 1; i++)
		{
			min = array[i];
			minpos = i;
			for (int j = i + 1; j < length; j++)
			{
				if (min < array[j])
				{
					min = array[j];
					minpos = j;
				}
			}
			swap(array[i], array[minpos]);
		}
	}
	else
	{
		int max, minpos; // For loop optimization
		for (int i = 0; i < length - 1; i++)
		{
			max = array[i];
			minpos = i;
			for (int j = i + 1; j < length; j++)
			{
				if (max > array[j])
				{
					max = array[j];
					minpos = j;
				}
			}
			swap(array[i], array[minpos]);
		}
	}

	return array;
}

void merge(std::vector<int>& array, int left, int mid, int right, bool reverse = false)
{
	// Creating two arrays
	// One array contains form array[left] to array[middle]
	// Other from array[middle + 1] to array[right]

	// Length of first array
	int leftLength = mid - left + 1;

	// Length of second array
	// right - (middle + 1) + 1
	//       = right - middle - 1 + 1
	//       = right - middle
	int rightLength = right - mid;

	int leftarray[leftLength];
	int rightarray[rightLength];

	for (int i = 0; i < leftLength; i++)
		leftarray[i]  = array[left + i];

	for (int i = 0; i < rightLength; i++)
		rightarray[i] = array[mid + i + 1];

	// Merging

	int leftpos  = 0;    // Keeps track of left array
	int rightpos = 0;    // Keeps track of right array
	int mainpos  = left; // Keeps track of main array

	while (leftpos < leftLength && rightpos < rightLength)
	{
		if (reverse)
		{
			if (leftarray[leftpos] > rightarray[rightpos])
			{
				array[mainpos] = leftarray[leftpos];
				leftpos++;
				mainpos++;
			}
			else
			{
				array[mainpos] = rightarray[rightpos];
				rightpos++;
				mainpos++;
			}
		}
		else
		{
			if (leftarray[leftpos] < rightarray[rightpos])
			{
				array[mainpos] = leftarray[leftpos];
				leftpos++;
				mainpos++;
			}
			else
			{
				array[mainpos] = rightarray[rightpos];
				rightpos++;
				mainpos++;
			}
		}
	}

	// Adding remaining elements

	while (leftpos < leftLength)
	{
		array[mainpos] = leftarray[leftpos];
		leftpos++;
		mainpos++;
	}

	while(rightpos < rightLength)
	{
		array[mainpos] = rightarray[rightpos];
		rightpos++;
		mainpos++;
	}
}

void mergeSort(std::vector<int>& array, int left, int right, bool reverse = false)
{
	if (reverse)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			mergeSort(array, left, mid, reverse = true);
			mergeSort(array, mid + 1, right, true);
			merge(array, left, mid, right, true);
		}
	}
	else
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			mergeSort(array, left, mid);
			mergeSort(array, mid + 1, right);
			merge(array, left, mid, right);
		}
	}
}
