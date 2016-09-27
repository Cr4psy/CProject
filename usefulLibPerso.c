/*strToInt function*/
//Return a int when given a str.

int strToInt(char* num){

  int i = 0;
  int val=0;
  
  while (num[i] != '\0') {//Go through all the char
    if (num[i]<48 || num[i]>57) {//Check that the string is a number
      return -1; //ERROR
    }
    
    val=10*val+(num[i]-48);//Convert code ASCII in int
    i++;
   }
  return val;
}

/*Random function*/
//Return a random number contained in the interval [a, b]

int randomNumberGenerator(int a, int b){
  return a + rand()%((b-a)+1);
}


/*Extract function*/
//Return vector from a ligne
void extractRow(double* vector, double** matrix, int ligne, int nbCol){
  int j=0;
  for (j=0; j<nbCol; j++) {
      vector[j]=matrix[ligne][j];//Copy row
    }

}
