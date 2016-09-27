/*Random function*/
//Return a random number contained in the interval [a, b]

int randomNumberGenerator(int a, int b){
  return a + rand()%((b-a)+1);
}

