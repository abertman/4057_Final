#include <stdio.h>
#include <stdlib.h>
#include "beta.h"

double beta(double stock_start, double baseline_start, double stock_end, double baseline_end) {
  
double Beta,stock_change,baseline_change;
stock_change = stock_end - stock_start;
baseline_change = baseline_end - baseline_start;
Beta = stock_change / baseline_change;
return Beta;

}
