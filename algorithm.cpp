void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int linear(int arr[], int length, int key)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == key)
			return i;
	}

	// If key is not found in the array
	return -1;
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

int min(int arr[], int length)
{
	int min = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int max(int arr[], int length)
{
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
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

void selectionSort(int arr[], int length)
{
	int min, minpos; // For loop optimization
	for (int i = 0; i < length - 1; i++)
	{
		min = arr[i];
		minpos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				minpos = j;
			}
		}
		swap(&arr[i], &arr[minpos]);
	}
}

void selectionSortReverse(int arr[], int length)
{
	int max, maxpos; // For loop optimization
	for (int i = 0; i < length - 1; i++)
	{
		max = arr[i];
		maxpos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (max > arr[j])
			{
				max = arr[j];
				maxpos = j;
			}
		}
		swap(&arr[i], &arr[maxpos]);
	}
}

void merge(int arr[], int left, int mid, int right)
{
	// Creating two arrays
	// One array contains form arr[left] to arr[middle]
	// Other from arr[middle + 1] to arr[right]

	// Length of first array
	int leftLength = mid - left + 1;

	// Length of second array
	// right - (middle + 1) + 1
	//       = right - middle - 1 + 1
	//       = right - middle
	int rightLength = right - mid;

	int leftarr[leftLength];
	int rightarr[rightLength];

	for (int i = 0; i < leftLength; i++)
		leftarr[i]  = arr[left + i];

	for (int i = 0; i < rightLength; i++)
		rightarr[i] = arr[mid + i + 1];

	// Merging

	int leftpos  = 0;    // Keeps track of left array
	int rightpos = 0;    // Keeps track of right array
	int mainpos  = left; // Keeps track of main array

	while (leftpos < leftLength && rightpos < rightLength)
	{
		if (leftarr[leftpos] < rightarr[rightpos])
		{
			arr[mainpos] = leftarr[leftpos];
			leftpos++;
			mainpos++;
		}
		else
		{
			arr[mainpos] = rightarr[rightpos];
			rightpos++;
			mainpos++;
		}
	}

	// Adding remaining elements

	while (leftpos < leftLength)
	{
		arr[mainpos] = leftarr[leftpos];
		leftpos++;
		mainpos++;
	}

	while(rightpos < rightLength)
	{
		arr[mainpos] = rightarr[rightpos];
		rightpos++;
		mainpos++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void mergeReverse(int arr[], int left, int mid, int right)
{
	// Creating two arrays
	// One array contains form arr[left] to arr[middle]
	// Other from arr[middle + 1] to arr[right]

	// Length of first array
	int leftLength = mid - left + 1;

	// Length of second array
	// right - (middle + 1) + 1
	//       = right - middle - 1 + 1
	//       = right - middle
	int rightLength = right - mid;

	int leftarr[leftLength];
	int rightarr[rightLength];

	for (int i = 0; i < leftLength; i++)
		leftarr[i]  = arr[left + i];

	for (int i = 0; i < rightLength; i++)
		rightarr[i] = arr[mid + i + 1];

	// Merging

	int leftpos  = 0;    // Keeps track of left array
	int rightpos = 0;    // Keeps track of right array
	int mainpos  = left; // Keeps track of main array

	while (leftpos < leftLength && rightpos < rightLength)
	{
		if (leftarr[leftpos] > rightarr[rightpos])
		{
			arr[mainpos] = leftarr[leftpos];
			leftpos++;
			mainpos++;
		}
		else
		{
			arr[mainpos] = rightarr[rightpos];
			rightpos++;
			mainpos++;
		}
	}

	// Adding remaining elements

	while (leftpos < leftLength)
	{
		arr[mainpos] = leftarr[leftpos];
		leftpos++;
		mainpos++;
	}

	while(rightpos < rightLength)
	{
		arr[mainpos] = rightarr[rightpos];
		rightpos++;
		mainpos++;
	}
}

void mergeSortReverse(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSortReverse(arr, left, mid);
		mergeSortReverse(arr, mid + 1, right);
		mergeReverse(arr, left, mid, right);
	}
}
