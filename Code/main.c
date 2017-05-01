#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ReadFile.h"
#include "beta.h"
#include "alpha.h"
#include "Output.h"

int main(int argc, char *argv[]){

int number_of_rows = 9150;

double *BaselinePrice = ReadFile("SP500",number_of_rows);

printf("Baseline Prices collected\n");

double *Price = ReadFile("AAPL",number_of_rows);

printf("Stock prices collected\n");

int i,j = 0;

int *Good_i = (int *)malloc(sizeof(int *)*(number_of_rows/25));
double *all_beta = (double *)malloc(sizeof(double *)*(number_of_rows/25));

double Beta, Alpha;

for (i = 0; i < (number_of_rows/25); i++){
	Beta = beta(Price[i*24],BaselinePrice[i*24],Price[i*24 + 24],BaselinePrice[i*24 + 24]);
	if ((Price[i*24 + 24]-Price[i*24]) > 0 && abs(Beta) > 1){
		Good_i[j] = i;
		all_beta[j]=Beta;
		// printf("%d\n",i );
		j++;
		// You've decided to buy the stock if these two conditions are met (ie it's trending up and it has a "large" beta value)
	}
}

printf("Beta is done\n");

i = 0;
double *all_alpha = (double *)malloc(sizeof(double *)*j);

while (i < j) {
	Alpha = alpha(Price[Good_i[i]*24],BaselinePrice[Good_i[i]*24],Price[Good_i[i]*24 + 24],BaselinePrice[Good_i[i]*24 + 24]);
	all_alpha[i]=Alpha;
	// Store Alpha somewhere
//	printf("%f\n",Alpha);
	i++;
}

printf("Alpha worked\n");

Output("AAPL",j,Good_i,all_beta,all_alpha);

return 0;
}
