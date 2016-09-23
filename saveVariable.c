/* This program save a integer given from the terminal*/

#include <stdio.h>

//Color for terminal
#define RED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"


int strToInt(char* num){//Convert a char into a int

  int i = 0;
  int val=0;
  
  while (num[i] != '\0') {//Go through all the char
    val=10*val+(num[i]-48);//Convert code ASCII in int
    i++;
   }
  return val;
}


int main(int argc, char *argv[])
{
  int nbOpt=0;
  int i = 0;
  int m = 0;
  nbOpt=argc-1;//Define the number of option (-1 because first option is the name of the prog)

  if (nbOpt == 1) {//Only one option admitted
    m = strToInt(argv[nbOpt]);//Convert char to int
    printf(GRN "The value %d has been saved.\n" RESET, m);
  }
  else {
    printf(RED "The number of parameters is incorrect !\nOnly one is admitted.\n" RESET);
  }
  return 0;
}

