#include <stdio.h>
#include "formulas.h"

int main(void) {
  int i;
  printf("%.2f\n", loanAmort(20000.00, 0.00625, 60));
  printf("%.2f\n", totalAssets(100000.00, 50000.00));
  printf("%.2f\n", netWorth(100.00, 50.00));
  printf("%.2f\n", breakEvenPrice(100000.00, 200.00, 0.4));
  printf("%.2f\n", breakEvenUnits(100000.00, 500.4, 0.4));
  printf("%.2f\n", simpleInterest(100.00, 0.07, 60));
  printf("%.2f\n", compoundInterest(100.00, 0.07, 0.09, 60));
  printf("%.2f\n", profitMargin(2000.00, 500.00));
  printf("%.2f\n", netIncome(500.00, 2000.00));
  printf("%.2f\n", burnRatePercentage(100000.00, 2000.00));
  printf("START CHART\n");
  for(i = 0; i < 4; i++) {
    double* chart = fiftyThirtyTwenty(4000.00);
    printf("%.2f\n", chart[i]);
  }
  printf("END CHART\n");
  printf("%.2f\n", ruleOf72(0.07));
  printf("%.2f\n", ruleOf25(20000.00));
  printf("%.2f\n", fourPercentWithdrawl(100000.00));
  printf("%.2f\n", averageNetIncome(200000.00, 25000.00));
  printf("%.2f\n", hoursOfLifeAsMoneyFormal(200000.00, 25000.00, 260, 8));
  printf("%.2f\n", hoursOfLifeAsMoneyReal(200000.00, 25000.00, 3500.00, 260, 8, 400));
  printf("%.2f\n", purchaseAsHoursOfLifeEquivilent(170.00, 16.00));
  
  return 0;
}
