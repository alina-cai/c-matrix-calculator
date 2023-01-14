#include <stdio.h>
#include <stdlib.h>  

int main() {
    
    // declare matrices
    int A[5][5];
    int B[5][5];
    int C[5][5]; 
    char dataA[20], input;
    
    // declare variables
    int rowsA, rowsB, rowsC;
    int columnsA, columnsB, columnsC;
    
    // declare file pointer and open file
    FILE* fptr;
    fptr = fopen("matrixIn.txt", "r");

    // double check file opening
    if (!fptr) {
        printf("Error opening file.");
        return 404;
    }

    // scan for and parse matrix A dimensions
    fgets(dataA, 20, fptr);
    sscanf(dataA, "%d %d", &rowsA, &columnsA);

    // read in matrix A numbers and print
    printf("Matrix A: \n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            fscanf(fptr, "%d  ", &A[i][j]);
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n"); // for cleaner formatting

    // scan for matrix B dimensions
    fscanf(fptr, "%d", &rowsB);
    fscanf(fptr, "%d", &columnsB);

    // read in matrix B numbers and print
    printf("Matrix B: \n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            fscanf(fptr, "%d  ", &B[i][j]);
            printf("%d  ", B[i][j]);
        }
        printf("\n");
    }

    // re-declare file pointer
    fptr = fopen("matrixOut.txt", "w");

    // ask user for input
    printf("\nEnter operation of choice (+/-/*): ");
    scanf("%c", &input);

    // returns output
    printf("\nOutput: \n");
    fprintf(fptr, "Output: \n");

    if (input == '+') {
        if (rowsA == rowsB && columnsA == columnsB) {
            printf("\nBoth rows and columns match.\n\n");
        }    
        else {
            printf("\nThe dimensions of the two matrices are not compatible.\n");
                return 0;
        }
        // sums matrix
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    else if (input == '-') {
        if (rowsA == rowsB && columnsA == columnsB) {
                printf("\nBoth rows and columns match.\n\n");
        }    
        else {
            printf("\nThe dimensions of the two matrices are not compatible.\n");
                return 0;
        }
        // subtracts matrix
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsA; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }   
        }
    }
    else if (input == '*') {
        if (columnsA == rowsB) {
            printf("\nColumn A matches row B.\n\n");
        }
        else {
            printf("\nThe dimensions of the two matrices are not compatible.\n");
            return 0;
        }
        // multiplies matrix
        for(int i = 0; i < rowsA; i++) {    
            for(int j = 0; j < columnsB; j++) {    
                C[i][j] = 0; 
                for(int k = 0; k < columnsA; k++) {    
                    C[i][j]+= A[i][k] * B[k][j]; 
                }    
            } 
        }    
    }
    else {
        printf("\nInvalid operation. Please try again.\n\n");
        return 0;
    }

    // print resulting matrix
    for(int i = 0; i < rowsA; i++) {     
        for(int j = 0; j < columnsA; j++) {    
            printf("%d  ", C[i][j]);   
            fprintf(fptr, "%d  ", C[i][j]); 
        }    
        printf("\n");  
        fprintf(fptr, "\n");  
    }    

    // close file
    fclose(fptr);
    return 0;

}