/*File reader*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileReader(char* fileName, double** matrix)
{
  FILE *fp = NULL;
  int c;
  int i =0;
  int j=0;
  int val =0;
  int dimMax = 1000;
  
   matrix = malloc(sizeof(double*) * dimMax);  
   for (i = 0; i < dimMax; i++) {
     matrix[i] = malloc(sizeof(double) * dimMax);   
   }
        
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
        //printf("i: %d j: %d\n", i,j);
        //        printf("%f\n", matrix[i][j]);
        i++;
        j=0;
        val=0;
      }
      else {//Convert ASCII to int
        val=10*val+(c-48);//Convert code ASCII in int
      }
      
    }//while
    
  }//else

  fclose(fp);//Close the file
  for (i; i<dimMax; i++) {//Free the space previously allocated.
     free(matrix[i]);
   }
  
    for (i = 0; i < 150; i++) {
    for (j=0; j< 2; j++) {
      printf(" %f \t", matrix[i][j]);
    }
    printf("\n");
    }
    printf("End of reader function \n");
return;
}


int main(int argc, char *argv[])
{
  char* fileName = "data.txt";
  int column = 2;
  int row = 150;
  int i = 0;
  int j=0;
  //  double** pt = NULL;
  //  double* ppt = NULL;
  //double matrix[row][column];
  double** matrix;
  //pt=&matrix[0][0];

  fileReader(fileName,matrix);
  //  printf("%f\n", matrix[4][1]);
   
  for (i = 0; i < row; i++) {
    for (j=0; j< column; j++) {
      
       printf("%f\t",matrix[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
//I don't know how to get the value from a double pointer!!!!!!
