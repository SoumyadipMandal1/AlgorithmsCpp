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

void permute(std::vector<std::vector<int>> &permutations, std::vector<int> permutation, std::vector<int> arr, std::vector<bool> &chosen)
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
