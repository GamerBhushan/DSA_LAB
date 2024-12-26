#include<stdio.h>

#define max_row 3
#define max_col 4

void displayMatrix(char message[],int row,int col, int matrix[row][col]);
void sparceMatrixRepresentation(int matrix[max_row][max_col]);
void fastTranspose(int tnzv,int sr[3][tnzv]);



void displayMatrix(char message[],int row,int col,int matrix[row][col]){
    printf("\n%s",message);
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void sparceMatrixRepresentation(int matrix[max_row][max_col]){   
    int total_non_zero = 0;
    for (int i = 0; i < max_row; i++){
        for ( int j = 0; j < max_col; j++){
            if (matrix[i][j] != 0){
                total_non_zero++;
            }
        }  
    }
    
    int sr[total_non_zero+1][3];
    sr[0][0] = max_row;
    sr[0][1] = max_col;
    sr[0][2] = total_non_zero;
    int k = 1;
    for (int i = 0; i < max_row; i++){
        for (int j = 0; j < max_col; j++){
            if (matrix[i][j] != 0){
                sr[k][0] = i;
                sr[k][1] = j;
                sr[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    displayMatrix("Sparce Matrix Representation\nRow\tColumn\tValue",total_non_zero+1,3,sr);
}

void fastTranspose(int tnzv,int sr[3][tnzv]){
    int total[max_col];

}

int main(){
    int matrix[3][4] = {
        {0,0,7,0},
        {8,0,5,0},
        {9,0,2,0}
    };
    displayMatrix("The Given Matrix Is :",max_row,max_col,matrix);
    sparceMatrixRepresentation(matrix);
}