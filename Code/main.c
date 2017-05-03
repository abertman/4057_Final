#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include "ReadFile.h"
#include "beta.h"
#include "alpha.h"
#include "Output.h"

int main(int argc, char *argv[]){

	clock_t start = clock();

	int number_of_rows = 9100, number_of_stocks = 16, number_of_days = 2; // # of stocks does NOT include S&P500

	char tickers[17][6] = {"SP500", "AAPL", "XOM", "AXP", "LMT", "NYT", "WMT", "NKE", "AET", "ALCO", "ALE", "BMY", "BRT", "CAT", "DCO", "DD", "DIS"};

	double *BaselinePrice = ReadFile(tickers[0],number_of_rows);

	int k;
	#pragma omp parallel for private(k) shared(tickers,BaselinePrice)
	for (k = 1; k <= number_of_stocks; k++) {

		double *Price = ReadFile(tickers[k],number_of_rows);

		int i,j = 0;

		int *Good_i = (int *)malloc(sizeof(int *)*(number_of_rows/number_of_days));
		double *all_beta = (double *)malloc(sizeof(double *)*(number_of_rows/number_of_days));

		double Beta, Alpha;

		for (i = 0; i < (number_of_rows/number_of_days); i++){
			Beta = beta(Price[i*(number_of_days-1)],BaselinePrice[i*(number_of_days-1)],Price[i*(number_of_days-1) + (number_of_days-1)],BaselinePrice[i*(number_of_days-1) + (number_of_days-1)]);
			if ((Price[i*(number_of_days-1) + (number_of_days-1)]-Price[i*(number_of_days-1)]) > 0 && abs(Beta) > 1){
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
			Alpha = alpha(Price[Good_i[i]*(number_of_days-1)],BaselinePrice[Good_i[i]*(number_of_days-1)],Price[Good_i[i]*(number_of_days-1) + (number_of_days-1)],BaselinePrice[Good_i[i]*(number_of_days-1) + (number_of_days-1)]);
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
		printf("%d\n",k );
	}

	printf("Code ran through successfully\n");

	double diff = (double)(clock() - start) / CLOCKS_PER_SEC;

	printf("Runtime: %f ms\n",diff*1000);

	return 0;
}
