#include <vector>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int linear(std::vector<int> arr, int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
            return i;
    }

    // If key is not found in the arr
    return -1;
}

int binaryLeft(std::vector<int> arr, int low, int high, int key)
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

int binaryRight(std::vector<int> arr, int low, int high, int key)
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

int interpolationSearch(std::vector<int> arr, int low, int high, int key)
{
    // Also checking if key is within the range of arr[low] and arr[high]
    while (low <= high and key >= arr[low] and key <= arr[high])
    {
        int mid = low + (high - low) * (key - arr[low]) / (arr[high] - arr[low]);

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int min(std::vector<int> arr)
{
    int min = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int minpair(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int max(std::vector<int> arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int maxpair(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

void permute(std::vector<std::vector<int>> &permutations, std::vector<int> permutation, std::vector<int> arr,
             std::vector<bool> &chosen)
{
    if (permutation.size() == arr.size())
        permutations.push_back(permutation);
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(arr[i]);
            permute(permutations, permutation, arr, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

std::vector<std::vector<int>> permutation(std::vector<int> arr)
{
    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation;

    // Initial value of all the elements is false
    std::vector<bool> chosen(arr.size(), false);

    permute(permutations, permutation, arr, chosen);

    return permutations;
}

/* The code for median of medians is written by taking reference from
 * the wikipedia article of the same name.
 * https://en.wikipedia.org/wiki/Median_of_medians*/

int partition5(std::vector<int> &arr, int left, int right)
{
    int i, j;

    // Sorting by bubble sort
    // As the number of elements sorted is atmost 5
    // So the type of sorting algorithm used does not matter
    i = left + 1;
    while (i <= right)
    {
        j = i;
        while (j > left and arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
        i++;
    }

    // returnig the median index after sorting
    return left + (right - left) / 2;
}

int select(std::vector<int> &, int, int, int);

int pivot(std::vector<int> &arr, int left, int right)
{
    // Returns the median index of the array directly if less than five elements are present
    if (right - left < 5)
        return partition5(arr, left, right);

    // If more elements are present
    // move the medians fo groups of five to the first n / 5 positions
    int median;
    int subright; // store the end position of each subarray
    for (int i = left; i <= right; i += 5)
    {
        subright = i + 4;
        // If the end position is more than the input
        if (subright > right)
            subright = right;
        // Index of median of each subarray
        median = partition5(arr, i, subright);

        // swapping the median to the first position
        swap(arr[median], arr[left + (i - left) / 5]);
    }

    // Index of median of all n / 5 medians-of-five
    median = (right - left) / 10 + left + 1;
    return select(arr, left, left + (right - left) / 5, median);
}

int partition(std::vector<int> &arr, int left, int right, int pivotIndex, int n)
{
    int pivotValue = arr[pivotIndex];
    // swaps pivot to the end of the array
    swap(arr[pivotIndex], arr[right]);

    // stores the index of elements smaller than the pivot value
    int index_smaller = left;

    // Move all elements smaller than the pivot to the left
    for (int i = left; i <= right - 1; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[i], arr[index_smaller]);
            index_smaller++;
        }
    }

    // stores the index of elements equal to the pivot value
    int index_equal = index_smaller;

    // Move all the elements equal to the pivot
    // right after the smaller elements
    for (int i = index_smaller; i <= right - 1; i++)
    {
        if (arr[i] == pivotValue)
        {
            swap(arr[i], arr[index_equal]);
            index_equal++;
        }
    }

    // Moving pivot to its final place
    swap(arr[index_equal], arr[right]);

    // Returning location of the pivot considering location n
    if (n < index_smaller)
        // n is with smaller elements
        return index_smaller;
    if (n <= index_equal)
        // n is in the group equal to pivot
        return n;
    // n is with larger elements
    return index_equal;
}

int select(std::vector<int> &arr, int left, int right, int n)
{
    while (true)
    {
        if (left == right)
            return left;

        // finding pivot element using median of medians
        int pivotIndex = pivot(arr, left, right);
        // partitioning the array
        pivotIndex = partition(arr, left, right, pivotIndex, n);

        if (n == pivotIndex)
            return n;
        else if (n < pivotIndex)
            right = pivotIndex - 1;
        else
            left = pivotIndex + 1;
    }
}

int nthSmallest(std::vector<int> &arr, int n)
{
    int index = select(arr, 0, arr.size() - 1, n - 1);
    return arr[index];
}
