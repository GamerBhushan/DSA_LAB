#include <stdio.h>
#include "SalesDatabase.c"


void swapSales(int a, int b)
{
    Sales temp;
    temp = sales[a];
    sales[a] = sales[b];
    sales[b] = temp;
}

// Partition function
int Partition(Sales sales[], int start, int end) {
    double pivot = sales[end].total_sale_amount; // Choose last element as pivot
    int i = start - 1; // Partition index

    for (int j = start; j < end; j++) {
        if (sales[j].total_sale_amount <= pivot) {
            i++;
            swapSales(i, j);
        }
    }

    swapSales(i + 1, end); // Place pivot in correct position
    return i + 1;
}

// QuickSort function
void QuickSort(Sales sales[], int start, int end) {
    if (start < end) {
        int pivotIndex = Partition(sales, start, end);
        QuickSort(sales, start, pivotIndex - 1); // Sort left partition
        QuickSort(sales, pivotIndex + 1, end);   // Sort right partition
    }
}


int main(int argc, char const *argv[]){
    displaySales();
    printf("\n--------------------------------- AFTER SORTING IN DESCENDING ORDER ----------------------------\n");
    QuickSort(sales,0,MAX_SALES-1);
    displaySales();
    return 0;
}
