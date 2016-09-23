//calculateEuclideanDistance

#include <stdio.h>
#include <math.h>


double calculateEuclideanDistance(double* vector1, double* vector2, int N){
  double val = 0.0;
  int i = 0;
  for (i = 0; i < N; i++) {
    val=val+(pow((vector1[i]-vector2[i]),2));
  }
  return sqrt(val);
}

int main(int argc, char *argv[])
{
  int N = 2;//Size of the vectors
  double vec1[2] = {10,6};
  double vec2[2] = {3,4};
  double value =0;
  //double* ptVec1 = &vec1[0];
  //double* ptVec2 = &vec2[0];
  
  //  printf("%f\n", ptVec1[1]);
  value = calculateEuclideanDistance(&vec1[0], &vec2[0], N);
  printf("%f\n", value);
  
  return 0;
}



