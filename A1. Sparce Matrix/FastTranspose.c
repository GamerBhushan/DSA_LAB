#include <stdio.h>

#define max_row 3
#define max_col 4

void displayMatrix(char message[], int row, int col, int matrix[row][col]);
void createSparceMatrix(int row, int col, int totalNonZeroValues, int matrix[row][col], int sparce[totalNonZeroValues + 1][3]);
void fastTranspose(int row, int col, int sparce_max_row, int sparce_max_col, int matrix[row][col], int sparce[sparce_max_col][sparce_max_row]);
void display1DArray(char message[], int size, int arr[size]);

void display1DArray(char message[], int size, int arr[size])
{
    printf("%s",message);
    for (int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
}

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

void createSparceMatrix(int row, int col, int totalNonZeroValues, int matrix[row][col], int sparce[totalNonZeroValues + 1][3])
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

void fastTranspose(int row, int col, int sparce_max_row, int sparce_max_col, int matrix[row][col], int sparce[sparce_max_col][sparce_max_row])
{
    int total[col];
    int non_zero_ele_in_col_count = 0;

    for (int i = 0; i < col; i++)
    {
        non_zero_ele_in_col_count = 0;
        for (int j = 0; j < row; j++)
        {
            if (matrix[j][i] != 0)
            {
                non_zero_ele_in_col_count++;
            }
        }
        total[i] = non_zero_ele_in_col_count;
        printf("\n");
    }

    int index[col + 1];
    index[0] = 1; // By Rule

    for (int i = 1; i < col + 1; i++)
    {
        index[i] = index[i - 1] + total[i - 1]; // Formula
    }

    display1DArray("\nThe Total Array Is :  ",col,total);
    display1DArray("\nThe Index Array Is :  ",col+1,index);

    int transpose[sparce_max_row][sparce_max_col];

    // transpose[0][0] = sparce[0][1];
    // transpose[0][1] = sparce[0][0];
    // transpose[0][2] = sparce[0][2];

    for (int i = 0; i < sparce_max_row; i++){
        int rowIndex = sparce[i][1];
        int placedAtRow = index[rowIndex];
        transpose[placedAtRow][0] = sparce[i][1];
        transpose[placedAtRow][1] = sparce[i][0];
        transpose[placedAtRow][2] = sparce[i][2];
        index[rowIndex]++;
    }
    displayMatrix("\n\nFast Transpose : \nRow\tColumn\tValue\n",sparce_max_row,sparce_max_col,transpose);

}

int main()
{
    int matrix[max_row][max_col] = {
        {0, 0, 7, 0},
        {8, 0, 5, 0},
        {9, 0, 2, 0}};

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
    createSparceMatrix(max_row, max_col, total_non_zero, matrix, sparce);
    displayMatrix("Sparce Matrix Representation : \nRow\tColumn\tValue\n", sparce_max_row, sparce_max_col, sparce);

    fastTranspose(max_row, max_col, sparce_max_row, sparce_max_col, matrix, sparce);
}