#include<stdio.h>
#include<stdlib.h>

double beta(double stock_start, double SPY_start, double stock_end, double SPY_end) {
  double beta,stock_change,SPY_change;
  stock_change=stock_end-stock_start;
  SPY_change=SPY_end=SPY_start;
  beta=stoc_changek/SPY_change;
  return beta;
}
