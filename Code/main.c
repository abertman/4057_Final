#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ReadFile.h"
#include "beta.h"
#include "alpha.h"

int main(int argc, char *argv[]){

int number_of_rows = 9150;

double *BaselinePrice = ReadFile("SP500",number_of_rows);

printf("Baseline Prices collected\n");

double *Price = ReadFile("AAPL",number_of_rows);

printf("Stock prices collected\n");

int i,j = 0;

int *Good_i = (int *)malloc(sizeof(int *)*(number_of_rows/25));

double Beta, Alpha;

for (i = 0; i < (number_of_rows/25); i++){
	Beta = beta(Price[i*24],BaselinePrice[i*24],Price[i*24 + 24],BaselinePrice[i*24 + 24]);
	if ((Price[i*24 + 24]-Price[i*24]) > 0 && abs(Beta) > 1){
		Good_i[j] = i;
		j++;
		// You've decided to buy the stock if these two conditions are met (ie it's trending up and it has a "large" beta value)
	}
}

printf("Beta is done\n");

i = 0;

while (i < j) {
	
	Alpha = alpha(Price[Good_i[i]*24],BaselinePrice[Good_i[i]*24],Price[Good_i[i]*24 + 24],BaselinePrice[Good_i[i]*24 + 24]);
	// Store Alpha somewhere
//	printf("%f\n",Alpha);
	i++;
}

printf("Alpha worked\n");

	// Find the trend of the stock
	// Send trend and beta value to a decision making function (returns 1 or 0)
	// If the decision is a BUY (1), see how the stock does the next month within function alpha.c
	// If decision is NO BUY (0), skip to end of loop
	// Store the returned alpha values somewhere, possible correlate them with date if possible so we can comment on whether we were more successful in some years than others


// Jump off a building when you see the total alpha value

return 0;
}
