/*Function that generate P matrix*/
//Create a matrix P with m different value taken from D matrix.
//Take only once each value

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
void extractRow(double* vector, double** matrix, int ligne, int nbRow);
int main(int argc, char *argv[])
{
    char* fileName = "data.txt";//Name of the file with data
      int dimMax = 1000;//Size of the temporaty array
  //Extract the data set from txt file.
  int i = 0;
  int j = 0;
  int nbCol = 0;
  int nbRow = 0;

  
 //Create pointer of pointers (matrix)
  double **matrix = NULL;//Named as D matrix
  
  //Allocate a temporary memory
  matrix = malloc(dimMax *sizeof *matrix);
  for (i = 0; i < dimMax; i++){
    matrix[i] = malloc(dimMax * sizeof *matrix[i]);  
  }
  
  //Extract value from file
  fileReader(fileName, matrix, &nbRow, &nbCol);
  double vecP[nbCol];
  extractRow(&vecP[0], matrix, 0, nbCol);

  for (i = 0; i < nbCol; i++) {
    printf("%f\n", vecP[i]);
  }

  
    
  //Free memory
  for (i=0; i<dimMax; i++) {
     	  free(matrix[i]);
   }
  free(matrix);
  
}



//Return vector from a ligne
void extractRow(double* vector, double** matrix, int ligne, int nbCol){
  int j=0;
  for (j=0; j<nbCol; j++) {
      vector[j]=matrix[ligne][j];//Copy row
    }

}
// FILE READER FUNCTION
void fileReader(char* fileName, double** matrix, int* nbRow, int* nbCol)
{

  FILE *fp = NULL;
  int c;
  int i =0;
  int j =0;
  int val =0;

  //Read file
  fp = fopen(fileName, "r");
  if (fp == NULL) {
    printf("No file found!\n");
  }
  else {
    printf("File open successfully!\n");
    i=0;
    j=0;

    while ((c = getc(fp)) != EOF) {
      if (c == 9) {//New column
        //        printf("i: %d , j: %d\n", i,j);
        matrix[i][j] = val;
        //        printf("%f\n", matrix[i][j]);
        j++;
        val=0;
      }
      else if (c == 10) {//New row
        matrix[i][j] = val;
        i++;
        j=0;
        val=0;
      }
      else {//Convert ASCII to int
        val=10*val+(c-48);//Convert code ASCII in int
      }
      if (j > *nbCol) *nbCol=j+1;
      if (i > *nbRow) *nbRow=i;
    }//while   
  }//else
 
  fclose(fp);//Close the file

 return;
}
