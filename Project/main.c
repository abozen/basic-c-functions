/**
* @file main.c
* @description fonksiyonları denediğimiz main fonksiyonu
* @assignment project1
* @date Kodu 11.12.2022
* @author Ahmet Burak Ozen (ahmetburak.ozen@stu.fsm.edu.tr)
*/

#include <stdio.h>
#include <stdlib.h>

#include"matrixLib.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int seed = atoi(argv[1]);
    srand(seed);
    
    float *v1 = returnVector(3);
    float *v2 = returnVector(3);
    float **mat1 = returnMatrix(3, 3);
    float **mat2 = returnMatrix(3, 3);
    float **mat3 = returnMatrix(3, 3);
    freeMatrix(mat3, 3);
    float meanv1= mean(v1, 3);
    float **matMul = matrixMultiplication(mat1, mat2, 3, 3, 3, 3);
    float **mat1Trans = matrixTranspose(mat1, 3, 3);
    float *mat1row = rowMeans(mat1, 3, 3);
    float *mat1col = columnMeans(mat1, 3, 3);
    float mat1det = determinant(mat1, 3);
    float corr = correlation(v1, v2, 3);
    
    
    printf("v1 vector: \n");
    printVector(v1, 3);
    printf("\n --------------------------\n");
    printf("v2 vector: \n");
    printVector(v2, 3);
    printf("\n --------------------------\n");
    printf("mat1 matrix: \n");
    printMatrix(mat1, 3, 3);
    printf("\n --------------------------\n");
    printf("mat2 matrix: \n");
    printMatrix(mat2, 3, 3);
    printf("\n --------------------------\n");
    printf("freed matrix: \n");
    printMatrix(mat3, 3, 3);
    printf("\n --------------------------\n");
    printf("mean of v1: %f \n",meanv1);
    printf("\n --------------------------\n");
    printf("mat1 row means: \n");
    printVector(mat1row, 3);
    printf("\n --------------------------\n");
    printf("mat1 column means: \n");
    printVector(mat1col, 3);
    printf("\n --------------------------\n");
    printf("determinant of mat1: %f \n", mat1det);
    printf("\n --------------------------\n");
    printf("correlation of v1 and v2: %f \n",corr);
    printf("\n --------------------------\n");
    
    
    
    
    return 0;
}

