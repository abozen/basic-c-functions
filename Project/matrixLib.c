/**
* @file matrixLib.c
* @description fonksiyon gövdelirinin bulunduğu dosya
* @assignment project1
* @date Kodu 11.12.2022
* @author Ahmet Burak Ozen (ahmetburak.ozen@stu.fsm.edu.tr)
*/

#include "matrixLib.h"
#include <stdio.h>
#include <stdlib.h>


float *returnVector(int size){
    float * ret = (float*)malloc(sizeof(float) * size);
    
    int r = rand();
    for (int i = 0; i < size; i++) {
        ret[i] = rand() % 10;
    }
    
    return ret;
}

float **returnMatrix(int row, int col){
    float **ret =(float**)malloc(sizeof(float*) * col);
    
    for (int i = 0; i < row; i++) {
        ret[i] = (float*)malloc(sizeof(float) * row);
    }
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            ret[i][j] = rand() % 10;
        }
    }
    
    return ret;
}


void freeMatrix(float **mat, int row){
    for (int i = 0; i < row; i++)
        free(mat[i]);
 
    free(mat);
}

float mean(float *vec, int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    return sum / size;
}

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2){
    if(col1 != row2)
        return 0;
    
    int col = col2;
    int row = row1;
    float **ret =(float**)malloc(sizeof(float*) * col);
    
    for (int q = 0; q < row; q++) {
        ret[q] = (float*)malloc(sizeof(float) * row);
    }
    int i, j, k;
    for (i = 0; i < col; i++) {
            for (j = 0; j < row; j++) {
                ret[i][j] = 0;
                for (k = 0; k < row; k++) {
                    ret[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    
    return ret;
    
}

float **matrixTranspose(float **mat, int row, int col){
    float **ret =(float**)malloc(sizeof(float*) * col);
    
    for (int i = 0; i < row; i++) {
        ret[i] = (float*)malloc(sizeof(float) * row);
    }
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            ret[i][j] = mat[j][i];
        }
    }
    return ret;
}

float *rowMeans(float **mat, int row, int col){
    float *ret =(float*)malloc(sizeof(float) * row);
    
    
    int sum;
    
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col; j++) {
            sum += mat[i][j];
        }
        ret[i] = sum / col;
    }
    return ret;
}

float *columnMeans(float **mat, int row, int col){
    float *ret =(float*)malloc(sizeof(float) * col);
    
    
    int sum;
    
    for (int i = 0; i < col; i++) {
        sum = 0;
        for (int j = 0; j < row; j++) {
            sum += mat[j][i];
        }
        ret[i] = sum / row;
    }
    return ret;
}

void printVector(float *vec, int N){
    for (int i = 0; i < N; i++) {
        printf("%f, ", vec[i]);
    }
}

void printMatrix(float **mat, int row, int col){
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf(" %f  ", mat[i][j]);
        }
        printf("\n");
    }
}

float determinant(float **mat, int row){
    for (int i = 0; i < row; i++) {
        mat[i] = (float*) realloc(mat[i], sizeof(float) * (row + row - 1));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row - 1; j++) {
            mat[i][row + j] = mat[i][j];
        }
    }
    float * negatives = (float*)malloc(sizeof(float) * row);
    float * positives = (float*)malloc(sizeof(float) * row);
    
    for(int i = 0; i < row; i++){
        negatives[i] = mat[0][(i+2)%row] * mat[1][(i+1)%row] * mat[2][i];
    }
    for(int i = 0; i < row; i++){
        positives[i] = mat[0][i] * mat[1][(i+1)%row] * mat[2][(i+2)%row];
    }
    float sum = 0;
    for(int i = 0; i < row; i++){
        sum += positives[i];
        
    }
    for(int i = 0; i < row; i++){
        sum -= negatives[i];
        
    }
    
    return sum;
}

float correlation(float *vec, float *vec2, int size){
    float mean1 = 0;
    float mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += vec[i];
    }
    for (int i = 0; i < size; i++) {
        mean2 +=vec2[i];
    }
    mean1 /= size; //mean of first vector
    mean2 /= size; //mean of second vector
    
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (vec[i] - mean1) * (vec2[i] - mean2);
    }
    
    return sum / (size - 1);
}

