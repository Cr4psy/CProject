//Randomness

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int randomNumberGenerator(int a, int b){
 
  int myRand =a + rand()%((b-a)+1);
  return myRand;
}

int main(int argc, char *argv[])
{
  int N = 100;
  int i =0;
   srand(time(NULL));
  for (i = 0; i < N; i++) {
  printf("%d\n", randomNumberGenerator(0,149));
    
  }

  return 0;
}

