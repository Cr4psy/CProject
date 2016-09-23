/* This program save a integer given from the terminal*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Color for terminal
#define RED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"


int strToInt(char* num){

  int i = 0;
  int val=0;
  
  while (num[i] != '\0') {//Go through all the char
    val=10*val+(num[i]-48);//Convert code ASCII in int
    i++;
   }
  return val;
}



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
        printf("i: %d , j: %d\n", i,j);
        matrix[i][j] = val;
        printf("%f\n", matrix[i][j]);
        j++;
        val=0;
      }
      else if (c == 10) {//New row
        matrix[i][j] = val;
        printf("i: %d j: %d\n", i,j);
         printf("%f\n", matrix[i][j]);
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

   for (i = 0; i<dimMax; i++) {
   free(matrix[i]);
   }
   free(matrix);
  
return;
}



int randomNumberGenerator(int a, int b){

  int myRand =a + rand()%((b-a)+1);
  return myRand;
}


double calculateEuclideanDistance(double* vector1, double* vector2, int N){
  double val = 0.0;
  int i = 0;
  for (i = 0; i < N; i++) {
    val=val+(pow((vector1[i]-vector2[i]),2));
  }
  return sqrt(val);
}



/*#############################################*/
int main(int argc, char *argv[])
{
  srand(time(NULL));
  /*******/
  //For file extraction (temporary)
  FILE *fp = NULL;
  int c;
  int val =0;
  int nbRow=150;
  int nbCol=2;
  double matrix[nbRow][nbCol+1];//+1 for p index later
  int nbIteration=0;
  /*************/

  int i=0;
  int j = 0;
   
  char* fileName = "data.txt";

  int column = 2;
  int row = 150;
  //  double** matrix;
  //double** mP;

 
  
  /********************************************************/
  //Extract the variable m from terminal
  int m = 0;
  int nbOpt = 0;
  printf("Take the m value from the terminal!\n");
  nbOpt=argc-1;//Define the number of option (-1 because first option is the name of the prog)
  if (nbOpt == 1) {//Only one option admitted
    m = strToInt(argv[nbOpt]);//Convert char to int
    printf(GRN "The value %d has been saved.\n" RESET, m);
  }
  else {
    printf(RED "The number of parameters is incorrect !\nOnly one is admitted.\n" RESET);
    return;
  }

  /*******************************************************/
  //Etract the data set from txt file.
  printf("Extract data from file !\n");
  //  fileReader(fileName, matrix);//Extract the value from *.txt//As the transfert of double pointer doesn't work, we will use it later
      
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
        printf("i: %d , j: %d\n", i,j);
        matrix[i][j] = val;
        printf("%f\n", matrix[i][j]);
        j++;
        val=0;
      }
      else if (c == 10) {//New row
        matrix[i][j] = val;
        printf("i: %d j: %d\n", i,j);
         printf("%f\n", matrix[i][j]);
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
  

  /*******************************************************/
  //Extrac m data point of matrix D and creates P

  
  /*  double* tmpMatrix = NULL;
  tmpMatrix = &matrix[0][0];
  for (i = 0; i < nbRow; i++) {
    for (j=0; j<nbCol; j++) {
      printf("Blabla :i: %d j: %d /t  %f\n",nbCol*i,j, *(tmpMatrix +nbCol*i+j));      
    }
  }
  */

  int myRandNum = 0;
  int randGenerated[m];
  int nbGenerated = 0;
  double mP[m][nbCol];

  
  printf("Generate the P matrix!\n");

  //Generate a random value and check that it's not been generated before
  for (i = 0; i < m; i++) {
    myRandNum = randomNumberGenerator(0,nbRow-1);   
    for (j=0; j<nbGenerated; j++) {      
      if (myRandNum == randGenerated[j]) {
        myRandNum = randomNumberGenerator(0, nbRow-1);
        j=0;
      }  
    }
    randGenerated[j] = myRandNum;
    //Copy the row
    for (j = 0; j<nbCol; j++) {
      mP[nbGenerated][j]=matrix[myRandNum][j];
    }  
    
    
    //printf("Random generated number : %d\n", myRandNum);
    //printf("x : %f \t y : %f\n", mP[nbGenerated][0],  mP[nbGenerated][1]);
    nbGenerated++;//Number of generated numbers
    
    //mP[i] = matrix[myRandNum];
  }


  /*****************************************************************************/
  /*****************************************************************************/
  //LOOP to converge to a right solution
int flag=0;
  do{
  
  

  /*****************************************************************************/
  //Compute the euclidean distance and compare with matrix P

  int N = nbCol;//Size of the vectors
  int iD = 0;
  int iP=0;
  double vecP[nbCol];
  double vecD[nbCol];
  double euclVal = 0;
  double euclValPre = 0;


  //Go through D matrix
  for (iD=0; iD<nbRow; iD++) {
    euclValPre = 0;
    //Vector D
    for (j=0; j<nbCol; j++) {
      vecD[j]=matrix[iD][j];//Copy row
    }

    for (iP = 0; iP<m; iP++) {//Go through P matrix
      //Vector P
      for (j = 0; j<nbCol; j++) {
        vecP[j]= mP[iP][j]; //Copy the row
      }
      
      //Compute euclidean distance
      euclVal = calculateEuclideanDistance(&vecP[0], &vecD[0], nbCol);

      if ((euclVal < euclValPre) || (euclValPre == 0)){
        matrix[iD][nbCol]=iP;//Add a column and give the closer parameters
        euclValPre=euclVal;
      }
    }
  }

  /*****************************************************************************/
  //Compute the new P value

  double mPprevious[m][nbCol];
  int nbOfSameClass[m];
  int index= 0;

  //Copy mP array in mPprevious
  for (i = 0; i<m; i++) {
    for (j=0; j<nbCol; j++) {
      mPprevious[i][j]=mP[i][j];
    }
    nbOfSameClass[i]=0; //Initialze array
  }

  //Sum the feature of D depending of mPindex and write inside mP
  for (i = 0; i<nbRow; i++) {//Go through all D matrix
    index = matrix[i][nbCol];//The index is given by the class of each data
    for (j=0; j<nbCol; j++) {//Go through column
      mP[index][j]+=matrix[i][j];
    }
    nbOfSameClass[index]+=1;//Give the number of data for each elements of P
  }

  //Compute the mean by dividing by the number of value of the same mPindex
  for (i = 0; i<m; i++) {
    for (j=0; j<nbCol; j++) {
      mP[i][j]=mP[i][j]/nbOfSameClass[i];
    }
  }



  /*****************************************************************************/
  //Compare new P value and old one
  flag = 1;
  for (i = 0; i<m; i++) {
    for (j=0; j<nbCol; j++) {
      if (mP[i][j] != mPprevious[i][j]) {
        flag = 0;
      }
    }
  }
  nbIteration++;
  }while (flag==0);//Loop as long as there is an improvment
  /*****************************************************************************/
  /*****************************************************************************/


  /******************************************************************************/
  //Print the result
  printf("Result find in %d iterations!\n", nbIteration);
  for (i = 0; i<m; i++) {
    printf("P : {");
    for (j=0; j<nbCol; j++) {
      printf(" %f ",mP[i][j]);
    }
    printf("}\n");
  }
    
  

  
  
  return 0;
}

