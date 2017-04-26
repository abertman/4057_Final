#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ReadFile.h"
#include "beta.h"

int main(int argc, char *argv[]){

int number_of_rows = 9150;

double *BaselinePrice = ReadFile("SP500",number_of_rows);

double *Price = ReadFile("AAPL",number_of_rows);

int i;

double Beta;

for (i = 0; i < (number_of_rows/25); i++){
	Beta = beta(Price[i*24],BaselinePrice[i*24],Price[i*24 + 24],BaselinePrice[i*24 + 24]);
	// Find the trend of the stock
	// Send trend and beta value to a decision making function (returns 1 or 0)
	// If the decision is a BUY (1), see how the stock does the next month within function alpha.c
	// If decision is NO BUY (0), skip to end of loop
	// Store the returned alpha values somewhere, possible correlate them with date if possible so we can comment on whether we were more successful in some years than others
}

// Jump off a building when you see the total alpha value

return 0;
}
