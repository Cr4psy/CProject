//Header

#ifndef FOO_H_
#define FOO_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Color for terminal
#define RED  "\x1B[31m" //Red
#define GRN   "\x1B[32m" //Green
#define YEL  "\x1B[33m" //Yellow
#define BLU  "\x1B[34m" //Blue
#define RESET "\x1B[0m" //White


int strToInt(char* num);//Convert from dtring to integer

int fileReader(char* fileName, double** matrix, int* nbCol, int* nbRow);//Fill matrix with number of fileName

int randomNumberGenerator(int a, int b);//Return a random number in the interval a to b

double calculateEuclideanDistance(double* vector1, double* vector2, int N);//Compute the euclidean distance of two vectors

void extractRow(double* vector, double** matrix, int ligne,int nbCol);//Return a vector from a matrix

#endif
