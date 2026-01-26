#include "algorithm.hpp"
#include <vector>

std::vector<int> bubbleSort(std::vector<int> arr, int length, bool reverse = false)
{
    if (reverse)
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] < arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

    return arr;
}

std::vector<int> insertionSort(std::vector<int> arr, int length, bool reverse = false)
{
    int key, j; // For Loop optimization

    if (reverse)
    {
        int key, j; // For Loop optimization
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
    else
    {
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

    return arr;
}

std::vector<int> selectionSort(std::vector<int> arr, int length, bool reverse = false)
{
    if (reverse)
    {
        int min, minpos; // For loop optimization
        for (int i = 0; i < length - 1; i++)
        {
            min = arr[i];
            minpos = i;
            for (int j = i + 1; j < length; j++)
            {
                if (min < arr[j])
                {
                    min = arr[j];
                    minpos = j;
                }
            }
            swap(arr[i], arr[minpos]);
        }
    }
    else
    {
        int max, minpos; // For loop optimization
        for (int i = 0; i < length - 1; i++)
        {
            max = arr[i];
            minpos = i;
            for (int j = i + 1; j < length; j++)
            {
                if (max > arr[j])
                {
                    max = arr[j];
                    minpos = j;
                }
            }
            swap(arr[i], arr[minpos]);
        }
    }

    return arr;
}

void merge(std::vector<int> &arr, int left, int mid, int right, bool reverse = false)
{
    // Creating two arrs
    // One arr contains form arr[left] to arr[middle]
    // Other from arr[middle + 1] to arr[right]

    // Length of first arr
    int leftLength = mid - left + 1;

    // Length of second arr
    // right - (middle + 1) + 1
    //       = right - middle - 1 + 1
    //       = right - middle
    int rightLength = right - mid;

    int leftarr[leftLength];
    int rightarr[rightLength];

    for (int i = 0; i < leftLength; i++)
        leftarr[i] = arr[left + i];

    for (int i = 0; i < rightLength; i++)
        rightarr[i] = arr[mid + i + 1];

    // Merging

    int leftpos = 0;    // Keeps track of left arr
    int rightpos = 0;   // Keeps track of right arr
    int mainpos = left; // Keeps track of main arr

    while (leftpos < leftLength && rightpos < rightLength)
    {
        if (reverse)
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

        else
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
    }

    // Adding remaining elements

    while (leftpos < leftLength)
    {
        arr[mainpos] = leftarr[leftpos];
        leftpos++;
        mainpos++;
    }

    while (rightpos < rightLength)
    {
        arr[mainpos] = rightarr[rightpos];
        rightpos++;
        mainpos++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right, bool reverse = false)
{
    if (reverse)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, reverse = true);
            mergeSort(arr, mid + 1, right, true);
            merge(arr, left, mid, right, true);
        }
    }
    else
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

int partition(std::vector<int> &arr, int low, int high)
{
    // Taking the middle element as the pivot
    int pivot = arr[low + (high - low) / 2];

    // Taking left and right outside of the array
    int left = low - 1;
    int right = high + 1;

    // Hoare's Partition
    while (true)
    {
        // Incrementing the left pointer
        // if the elements at left is already smaller than pivot
        do
        {
            left++;
        } while (arr[left] < pivot);

        // Decrementing the left pointer
        // if the elements at right is already larher than pivot
        do
        {
            right--;
        } while (arr[right] > pivot);

        // If no more swapping is possible
        if (left >= right)
            return right;

        // If an element at the left pointer is greater than pivot and
        // the element at the right pointer is smaller than pivot
        swap(arr[left], arr[right]);
    }
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        // Hoare's partition returns a split point, not a pivot position
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void heapify(std::vector<int> &arr, int index, int length)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largestNode = index;

    if (left < length && arr[left] > arr[largestNode])
        largestNode = left;
    if (right < length && arr[right] > arr[largestNode])
        largestNode = right;

    if (largestNode != index)
    {
        swap(arr[largestNode], arr[index]);
        heapify(arr, largestNode, length);
    }
}

void buildMaxHeap(std::vector<int> &arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, i, arr.size());
}

void heapSort(std::vector<int> &arr)
{
    buildMaxHeap(arr);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
