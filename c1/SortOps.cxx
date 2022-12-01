#include "SortOps.h"

// Create private memberrs

/**
 * @brief Implements a swappingg of array elements
 * 
 */
void SortOps::swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Implements a partitioning of the array
 * 
 * @return uint64_t 
 */
uint64_t SortOps::Partition(int* arr, uint64_t low, uint64_t high)
{
    // Set the pivot to the last element
    int pivot = arr[high];
    // Set the index of the smaller element
    uint64_t i = low - 1;
    // Iterate through the array
    for (uint64_t j = low; j < high; j++)
    {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            // Increment the index of the smaller element
            i++;
            // Swap the current element with the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot with the smaller element
    swap(&arr[i + 1], &arr[high]);
    // Return the index+1 of the smaller element from the pivot (included) to the right
    return i + 1;
}

// Create public members

/**
 * @brief Destroy the Sort Ops:: Sort Ops object
 * 
 */
SortOps::~SortOps()
{
}

/**
 * @brief Implements a quick sort
 * 
 */
void SortOps::quickSort(int* arr, uint64_t low, uint64_t high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        uint64_t pi = Partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}