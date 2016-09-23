#include <stdio.h>

void fileo(int *matrix){


  *matrix = 3;

}


int main(int argc, char *argv[])
{
  int matrix = 0;
  void* a = &matrix;
  printf("%d\n", matrix);
  fileo(a);
  printf("%d\n", matrix);
  return 0;
}


