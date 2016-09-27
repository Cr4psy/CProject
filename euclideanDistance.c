/*Function calculateEuclideanDistance*/
//Return the euclidean distance when two vectors are given*/

#include <math.h>

double calculateEuclideanDistance(double* vector1, double* vector2, int N){
  double val = 0.0;
  int i = 0;
  for (i = 0; i < N; i++) {
    val=val+(pow((vector1[i]-vector2[i]),2));//SUM((v1-v2)^2)
  }
  return sqrt(val);
}
