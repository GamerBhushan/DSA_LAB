/*
 Write a program to represent sparse matrix using array 
 and perform simple and fast transpose
*/


#include <stdio.h>

// Function to represent the sparse matrix
void createSparseMatrix(int matrix[][10], int rows, int cols, int sparse[][3]) {
    int k = 1; // Sparse matrix row index
    sparse[0][0] = rows; // Total rows in the original matrix
    sparse[0][1] = cols; // Total columns in the original matrix
    sparse[0][2] = 0;    // Total non-zero elements

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;      // Row index
                sparse[k][1] = j;      // Column index
                sparse[k][2] = matrix[i][j]; // Non-zero value
                k++;
            }
        }
    }
    sparse[0][2] = k - 1; // Update the count of non-zero elements
}

// Function to perform simple transpose
void simpleTranspose(int sparse[][3], int transpose[][3]) {
    int n = sparse[0][2]; // Number of non-zero elements
    transpose[0][0] = sparse[0][1]; // Rows become columns
    transpose[0][1] = sparse[0][0]; // Columns become rows
    transpose[0][2] = n;

    for (int i = 1; i <= n; i++) {
        transpose[i][0] = sparse[i][1]; // Swap row and column
        transpose[i][1] = sparse[i][0];
        transpose[i][2] = sparse[i][2]; // Copy value
    }
}

// Function to perform fast transpose
void fastTranspose(int sparse[][3], int transpose[][3]) {
    int row_terms[10] = {0}, starting_pos[10] = {0};
    int rows = sparse[0][0], cols = sparse[0][1], n = sparse[0][2];

    transpose[0][0] = cols; // Transpose rows and columns
    transpose[0][1] = rows;
    transpose[0][2] = n;

    // Count the number of elements in each column
    for (int i = 1; i <= n; i++) {
        row_terms[sparse[i][1]]++;
    }

    // Determine starting position for each column in the transposed matrix
    starting_pos[0] = 1;
    for (int i = 1; i < cols; i++) {
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    }

    // Fill the transpose matrix using starting positions
    for (int i = 1; i <= n; i++) {
        int col = sparse[i][1];
        int pos = starting_pos[col];
        transpose[pos][0] = sparse[i][1]; // Column becomes row
        transpose[pos][1] = sparse[i][0]; // Row becomes column
        transpose[pos][2] = sparse[i][2]; // Copy value
        starting_pos[col]++;
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(int sparse[][3]) {
    int n = sparse[0][2]; // Number of non-zero elements
    printf("Rows Columns Value\n");
    for (int i = 0; i <= n; i++) {
        printf("%4d %7d %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[4][10] = {
        {0, 0, 3, 0},
        {0, 0, 5, 0},
        {0, 7, 0, 0},
        {9, 0, 0, 0}
    };

    int sparse[10][3], simpleT[10][3], fastT[10][3];

    // Create sparse matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    createSparseMatrix(matrix, 4, 4, sparse);

    // Display sparse matrix
    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparse);

    // Perform simple transpose
    simpleTranspose(sparse, simpleT);
    printf("\nSimple Transpose of Sparse Matrix:\n");
    displaySparseMatrix(simpleT);

    // Perform fast transpose
    fastTranspose(sparse, fastT);
    printf("\nFast Transpose of Sparse Matrix:\n");
    displaySparseMatrix(fastT);

    return 0;
}
