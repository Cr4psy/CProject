/*File reader*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ALWAYS declare function before use
void fileReader(char* fileName, double** matrix, int* nbRow, int* nbCol);

// ALWAYS have main on top :)
int main(int argc, char *argv[])
{
  char* fileName = "data.txt";
  int nbCol = 0;
  int nbRow = 0;
  int i = 0;
  int j = 0;
  int dimMax = 1000;

  //Create matrix of pointers
  double **matrix; // = (double**)malloc(dimMax * sizeof(double*);
  //Allocate a tempory memory
  matrix = malloc(dimMax *sizeof *matrix);
  for (i = 0; i < dimMax; i++){
    matrix[i] = malloc(dimMax * sizeof *matrix[i]); // (double*)malloc(sizeof(double) * dimMax);  
  }
  
  
  //Extract value from file
  fileReader(fileName, matrix, &nbRow, &nbCol);

  printf("%d %d\n", nbRow, nbCol);
  printf("HELLOE\n");
  for (i = 0; i < nbRow; i++) {
    for (j=0; j< nbCol; j++) {
      
       printf("%f\t",matrix[i][j]);
    }
    printf("\n");
  }
  


  //Free memory
  for (i=0; i<dimMax; i++) {
     	  free(matrix[i]);
   }
  free(matrix);
  return 0;
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

//I don't know how to get the value from a double pointer!!!!!!