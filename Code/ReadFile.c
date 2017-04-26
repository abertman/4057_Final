#include "Read.h"
#include <stdio.h>
#include <stdlib.h>

double ReadFile(char Ticker[]){

char filename[20];

snprintf(filename,"./Data/%s.csv",Ticker);

int number_of_rows = 9150;

FILE *filehandle = fopen(filename,"r");

for (i = 0; i < number_of_rows; i++){
	fprintf(filehandle,"%s %f",void,Price[i]);
}

return Price;

}
