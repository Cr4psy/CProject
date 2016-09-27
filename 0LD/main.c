/* This program save a integer given from the terminal*/

#include "header.h"


//Global variable

int nbCol = 0;
int nbRow = 0;


/*#############################################*/
int main(int argc, char *argv[])
{
  srand(time(NULL));

  //Initialisation
  const int  dimMax = 1000;//Size of the temporaty array
  char* fileName = "data.txt";//Name of the file with data
  
  int i=0;
  int j=0;
  int nbIteration=0;

   

  
  /********************************************************/
  //Extract the variable m from terminal
  int m = 0;
  int nbOpt = 0;
  printf("Read the value from the terminal.\n");
  nbOpt=argc-1;//Define the number of option (-1 because first option is the name of the prog)
  if (nbOpt == 1) {//Only one option admitted
    m = strToInt(argv[nbOpt]);//Convert char to int

    if (m == -1) {//Error, if Nan input
      printf(RED "Incorrect parameter, it must be a real positif number.\n" RESET);
      return 1;
    }
   
    printf(GRN "The value %d has been saved.\n" RESET, m);
  }
  else {//Error, too many inputs
    printf(RED "The number of parameters is incorrect !\nOnly one is admitted.\n" RESET);
    return 1;
  }

  /*******************************************************/
  //Extract the data set from txt file.

 //Create pointer of pointers (matrix)
  double **matrix = NULL;//Named as D matrix
  
  //Allocate a temporary memory
  matrix = malloc(dimMax *sizeof *matrix);
  for (i = 0; i < dimMax; i++){
    matrix[i] = malloc(dimMax * sizeof *matrix[i]);  
  }
  
  //Extract value from file
  if (fileReader(fileName, matrix, &nbCol, & nbRow)){
      printf(RED "Error : no data!\n" RESET);
      return 1;
    }
  
  /*******************************************************/
  //Extrac m data point of matrix D and creates P
  int myRandNum = 0;
  int randGenerated[m];
  int nbGenerated = 0;
  double mP[m][nbCol];

  
  printf("Generate the P matrix.\n");

  //Generate a random value and check that it's not been generated before
  for (i = 0; i < m; i++) {
    myRandNum = randomNumberGenerator(0,nbRow-1);   
    for (j=0; j<nbGenerated; j++) {      
      if (myRandNum == randGenerated[j]) {
        myRandNum = randomNumberGenerator(0, nbRow-1);
        j=0;//Recontrole that the new value is unique
      }  
    }
    randGenerated[j] = myRandNum;//Save which number has been generated

    
    //Copy the row from D to P
    for (j = 0; j<nbCol; j++) {
      mP[nbGenerated][j]=matrix[myRandNum][j];
    }  
    
    nbGenerated++;//Number of generated numbers
  }


  /*****************************************************************************/
  /*****************************************************************************/
  //LOOP to converge to a right solution
  printf("Research the centroids...\n");
int flag=0;
  do{
  
  

  /*****************************************************************************/
  //Compute the euclidean distance and compare with matrix P

   int iD = 0;//index of D matrix
  int iP = 0;//index of P matrix
  double vecP[nbCol];
  double vecD[nbCol];
  double euclVal = 0;
  double euclValPre = 0;


  //Go through D matrix
  for (iD=0; iD<nbRow; iD++) {
    euclValPre = 0;

    extractRow(&vecD[0], matrix, iD, nbCol);//Vector D
    
    for (iP = 0; iP<m; iP++) {//Go through P matrix
      for (j=0; j <nbCol ; j++) {
        vecP[j]=mP[iP][j];
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

  //Compute the average value from all same feature with same class in D and add to P
  for (i = 0; i<nbRow; i++) {//Go through all D matrix
    index = matrix[i][nbCol];//The index is given by the class of each data
    for (j=0; j<nbCol; j++) {//Go through column
      mP[index][j]+=matrix[i][j];
    }
    nbOfSameClass[index]+=1;//Give the number of data added for each elements of P
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
  int nbResult=0;
  
  for (i = 0; i<m; i++) {
    if (!isinf(mP[i][0])) {
      nbResult++;
      printf(YEL "P : {");
      for (j=0; j<nbCol; j++) {
        printf(" %f ",mP[i][j]);
      }
      printf("}\n"RESET);
    }
  }
  printf(GRN "%d centroids found in %d iterations!\n" RESET, nbResult, nbIteration);
    
  /******************************************************************************/
  //Free memory
  for (i=0; i<dimMax; i++) {
     	  free(matrix[i]);
   }
  free(matrix);
  
  return 0;
}




