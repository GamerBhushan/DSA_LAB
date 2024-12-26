#include <stdio.h>

#define max_row 3
#define max_col 4

void displayMatrix(char message[], int row, int col, int matrix[row][col]);
void createSparceMatrix(int row, int col, int totalNonZeroValues, int matrix[row][col], int sparce[totalNonZeroValues+1][3]);
void fastTranspose(int tnzv, int sr[3][tnzv]);

void displayMatrix(char message[], int row, int col, int matrix[row][col])
{
    printf("\n%s", message);
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void createSparceMatrix(int row, int col, int totalNonZeroValues, int matrix[row][col], int sparce[totalNonZeroValues+1][3])
{

    sparce[0][0] = max_row;
    sparce[0][1] = max_col;
    sparce[0][2] = totalNonZeroValues;
    int k = 1;
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_col; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparce[k][0] = i;
                sparce[k][1] = j;
                sparce[k][2] = matrix[i][j];
                k++;
            }
        }
    }
}

void fastTranspose(int tnzv, int sr[3][tnzv])
{
    int total[max_col];
}

int main()
{
    int matrix[3][4] = {
        {0, 0, 7, 0},
        {8, 0, 5, 0},
        {9, 0, 2, 0}
    };

    int total_non_zero = 0;
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_col; j++)
        {
            if (matrix[i][j] != 0)
            {
                total_non_zero++;
            }
        }
    }
    int sparce_max_row = total_non_zero + 1, sparce_max_col = 3;
    int sparce[sparce_max_row][sparce_max_col];

    displayMatrix("The Given Matrix Is :", max_row, max_col, matrix);
    createSparceMatrix(max_row,max_col,total_non_zero,matrix,sparce);
    displayMatrix("Sparce Matrix Representation : \nRow\tColumn\tValue\n",sparce_max_row,sparce_max_col,sparce);
}