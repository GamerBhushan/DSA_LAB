#include <stdio.h>


#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void BubbleSort(int size, int data[], int type);

#endif // BUBBLESORT_H



 

int generateRandomInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min; // Generate random number in range
}

void BubbleSort(int size, int data[], int type) {
    if (type == 0) { // Sorting in Ascending Order
        for (int i = 0; i < size - 1; i++) {
            int swapped = 0; // Optimization: Check if any swapping occurred
            for (int j = 0; j < size - i - 1; j++) { // Only go up to unsorted portion
                if (data[j] > data[j + 1]) {
                    int tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                    swapped = 1; // Mark that a swap occurred
                }
            }
            if (!swapped) break; // Exit early if no swaps happened
        }
    } else if (type == 1) { // Sorting in Descending Order
        for (int i = 0; i < size - 1; i++) {
            int swapped = 0; // Optimization: Check if any swapping occurred
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] < data[j + 1]) {
                    int tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                    swapped = 1; // Mark that a swap occurred
                }
            }
            if (!swapped) break; // Exit early if no swaps happened
        }
    } else {
        printf("\n\nUndefined Type: Choose '0' for Ascending or '1' for Descending\n\n");
    }
}

void display(int size, int data[])
{
    for (int i = 0; i < 20; i++)
    {
        if (i == 19)
        {
            printf(" %d ", data[i]);
        }
        else
        {
            printf(" %d, ", data[i]);
        }
    }
}

void changeValue(int data[]){
    data[0] = 0;
    data[1] = 0;
}
