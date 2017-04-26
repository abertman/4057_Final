#include "ReadFile.h"
#include <stdio.h>
#include <stdlib.h>

double *ReadFile(char Ticker[],int number_of_rows){

char filename[20];

snprintf(filename,20,"%s.csv",Ticker);

FILE *filehandle = fopen(filename,"r");

int i;

double *Price = (double *)malloc(sizeof(double *)*number_of_rows);


for (i = 0; i < number_of_rows; i++){
//	printf("%d\n",i);
//	fscanf(filehandle,"%lf",&Price[i]);
	fscanf(filehandle,"%*[^,],%lf",&Price[i]);
//	printf("%f\n",holder);
}

fclose(filehandle);

return Price;

}
