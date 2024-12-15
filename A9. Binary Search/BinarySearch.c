#include <stdio.h>

int BinarySearch(int target, int start, int end, int arr[])
{
    if (start > end)
    {
        return -1; // Base case: target not found
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target)
    {
        return mid; // Target found
    }
    else if (target < arr[mid])
    {
        return BinarySearch(target, start, mid - 1, arr); // Search in the left half
    }
    else
    {
        return BinarySearch(target, mid + 1, end, arr); // Search in the right half
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d", BinarySearch(11, 0, 9, arr));
    return 0;
}
