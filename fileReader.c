/*File reader function*/

#include <stdio.h>

//Color for terminal
#define RED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

// FILE READER FUNCTION
int fileReader(char* fileName, double** matrix, int* nbCol, int* nbRow)
{

  FILE *fp = NULL;
  int c;
  int i =0;
  int j =0;
  int val =0;


  printf("Opening the file...\n");
  //Read file
  fp = fopen(fileName, "r");
  if (fp == NULL) {
    printf(RED "No file found!\n" RESET);
    return 1;
  }
  else {
    printf(GRN "File open successfully!\n" RESET);
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
    fclose(fp);//Close the file
  }//else
 


 return 0;
}

