#include<stdio.h>
#include<stdlib.h>

double alpha(double stock_start, double SPY_start, double stock_end, double SPY_end) {
  double alpha,stock_change,SPY_change;
  stock_change=(stock_end-stock_start)/(stock_start);
  SPY_change=(SPY_end-SPY_start)/(SPY_start);
  alpha=100*(stock_change-SPY_change);
  return alpha;
}
