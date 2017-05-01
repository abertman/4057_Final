#include "ReadFile.h"
#include <stdio.h>
#include <stdlib.h>

double *ReadFile(char Ticker[],int number_of_rows){

char filename[20];

snprintf(filename,20,"%s.csv",Ticker);

FILE *filehandle = fopen(filename,"r");

int i;

double holder;

double *Price = (double *)malloc(sizeof(double *)*number_of_rows);

for (i = 0; i < number_of_rows; i++){
	fscanf(filehandle,"%*f%*c%*f%*c%*f%*c%lf",&Price[i]);
}

fclose(filehandle);

return Price;

}
