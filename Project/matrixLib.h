/**
* @file main.c
* @description fonksiyonların protatiplerinin bulunduğu header file
* @assignment project1
* @date Kodu 11.12.2022
* @author Ahmet Burak Ozen (ahmetburak.ozen@stu.fsm.edu.tr)
*/

#ifndef matrixLib_h
#define matrixLib_h

#include <stdio.h>

float *returnVector(int size);
float **returnMatrix(int row, int col);
void freeMatrix(float **mat, int row);
float mean(float *vec, int size);
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);
float **matrixTranspose(float **mat, int row, int col);
float *rowMeans(float **mat, int row, int col);
float *columnMeans(float **mat, int row, int col);
void printVector(float *vec, int N);
void printMatrix(float **mat, int row, int col);
float determinant(float **mat, int row);
float correlation(float *vec, float *vec2, int size);

#endif /* matrixLib_h */
