#include "formulas.h"

double loanAmort(double initialPrincipal, double periodicInterestRate, double numberOfPayments) {
  double num = pow(1 + periodicInterestRate, numberOfPayments) * periodicInterestRate;
  double den = pow(1 + periodicInterestRate, numberOfPayments) - 1;

  double quo = num / den;
  
  return printf("%.2f", quo * initialPrincipal);
}

double totalAssets(double equity, double liabilities) {
  return printf("%.2f", equity + liabilities);
}

double netWorth(double assets, double liability) {
  return printf("%.2f", assets - liability);
}

double breakEvenPrice(double totalFixedCost, double unitVolume, double variableCost) {
  return printf("%.2f", (totalFixedCost / unitVolume) + variableCost);
}

double breakEvenUnits(double totalFixedCost, double salesPrice, double variableCost) {
  double den = salesPrice - variableCost;
  
  return printf("%.2f", totalFixedCost / den);
}

double simpleInterest(double principal, double rate, double time) {
  return printf("%.2f", principal * rate * time);
}

double compoundInterest(double initialPrincipal, double rate, double interest, double time) {
  double res0 = (rate / interest) + 1;
  double res1 = pow(res0, (interest * time));
  
  return printf("%.2f", initialPrincipal * res1);
}

double profitMargin(double profit, double revenue) {
  return printf("%.2f", (profit / revenue) * 100);
}

double netIncome(double revenue, double totalCost) {
  return printf("%.2f", revenue - totalCost);
}

double burnRatePercentage(double totalCost, double totalRevenue) {
  return printf("%.2f", totalCost / totalRevenue);
}

double fiftyThirtyTwenty(double revenue) {
  double needs = revenue * 0.5;
  double wants = revenue * 0.3;
  double save = revenue * 0.2;

  return printf("Revenues = %.2f\nNeeds = %.2f\nWants = %.2f\nSavings = %.2f", revenue, needs, wants, save);
}

double ruleOf72(double interestRate) {
  return printf("%.1f", 72 / interestRate);
}

double ruleOf25(double annualCosts) {
  return printf("%.2f", annualCosts * 25);
}

double fourPercentWithdrawl(double nestEgg) {
  return printf("%.2f", 0.04 * nestEgg);
}

double averageNetIncome(double grossIncome, double taxes) {
  return printf("%.2f", grossIncome - taxes);
}

double hoursOfLifeAsMoneyFormal(double annualGrossIncome, double taxes, double daysWorked, double hoursWorked) {
  double annualNetIncome = annualGrossIncome - taxes;
  double averageYearHoursWorked = daysWorked * hoursWorked;

  return printf("%.2f", annualNetIncome / averageYearHoursWorked);
}

double hoursOfLifeAsMoneyReal(double annualGrossIncome, double taxes, double jobRelatedCosts, double daysWorked, double hoursWorked, double extraWorkHours) {
  double annualNetIncome = annualGrossIncome - taxes;
  double totalIncome = annualNetIncome - jobRelatedCosts;
  double averageYearHoursWorked = daysWorked * hoursWorked;
  double totalHoursWorked = averageYearHoursWorked + extraWorkHours;

  return printf("%.2f", totalIncome / totalHoursWorked);
}

double purchaseAsHoursOfLifeEquivilent(double moneySpent, double realHourlyRate) {
  return printf("%.2f", moneySpent / realHourlyRate);
}

double lifetimeWealthRatio(double netWorth, double totalLifetimeIncome) {
  return printf("%.2f", netWorth / totalLifetimeIncome);
}
