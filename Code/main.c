#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "ReadFile.h"
#include "beta.h"
#include "alpha.h"
#include "Output.h"

int main(int argc, char *argv[]){

clock_t start = clock();

int number_of_rows = 9100, number_of_stocks = 7; // # of stocks does NOT include S&P500

char tickers[8][6] = {"SP500", "AAPL", "XOM", "AXP", "LMT", "NYT", "WMT", "NKE"};

double *BaselinePrice = ReadFile(tickers[0],number_of_rows);

int k;

for (k = 1; k <= number_of_stocks; k++) {

double *Price = ReadFile(tickers[k],number_of_rows);

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

i = 0;
double *all_alpha = (double *)malloc(sizeof(double *)*j);

while (i < j) {
	Alpha = alpha(Price[Good_i[i]*24],BaselinePrice[Good_i[i]*24],Price[Good_i[i]*24 + 24],BaselinePrice[Good_i[i]*24 + 24]);
	all_alpha[i]=Alpha;
	// Store Alpha somewhere
//	printf("%f\n",Alpha);
	i++;
}

Output(tickers[k],j,Good_i,all_beta,all_alpha);

free(all_alpha);
free(all_beta);
free(Good_i);
free(Price);

}

free(BaselinePrice);

printf("Code ran through successfully\n");

double diff = (double)(clock() - start) / CLOCKS_PER_SEC;

printf("Runtime: %f ms\n",diff*1000);

return 0;
}
