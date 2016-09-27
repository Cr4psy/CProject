#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0;
    int j=0;
    int f=1;
    char car;
    double tmpVal=0;
    int max = 1000;
double** matrix=NULL; //pointer points to pointer with adress NULL and value undetermined.
    FILE *project_file;  
 int nbData=0;
 int nbRow=0;
 int nbCol = 0;
    
matrix=malloc(max*sizeof(double*)); // Allocate memory to matrix of size 1000*1byte(size of double pointer)
for(i=0; i<max; ++i){ 
matrix[i]=malloc(2*sizeof(double));
}

 project_file = fopen("data.txt", "r");

 
 i=0;
 j=0;
 do{
   
 f= fscanf(project_file, "%lf%c",&tmpVal,&car);


 if (f>0) {
   matrix[i][j]=tmpVal;
   if (car=='\t') {
     j++;
   }
   else if (car == '\n') {
     i++;
     j=0;
   }
   nbData++;
 }

 }while(f>0);

 nbRow= i;
 nbCol = nbData/i;

for (i = 0; i<nbRow; i++) {
  for (j=0; j<nbCol; j++) {
    printf("%f\t", matrix[i][j]);
  }
  printf("\n");
}
 
for (i=0; i<max; ++i){
    free(matrix[i]);
}
free(matrix);

    return 0;
}
