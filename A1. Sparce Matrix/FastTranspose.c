#include<stdio.h>

#define max_row 3
#define max_col 4

void displayMatrix(char message[],int matrix[max_row][max_col]){
    printf("\n%s",message);
    printf("\n");
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_col; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[3][4] = {
        {0,0,7,0},
        {8,0,5,0},
        {9,0,2,0}
    };

    displayMatrix("The Given Matrix Is :",matrix);
}