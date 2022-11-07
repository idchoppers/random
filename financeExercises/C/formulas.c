#include "formulas.h"

double loanAmort(double initialPrincipal, double periodicInterestRate, double numberOfPayments) {
  double num = pow(1 + periodicInterestRate, numberOfPayments) * periodicInterestRate;
  double den = pow(1 + periodicInterestRate, numberOfPayments) - 1;

  double quo = num / den;
  
  return quo * initialPrincipal;
}

double totalAssets(double equity, double liabilities) {
  return equity + liabilities;
}

double netWorth(double assets, double liability) {
  return assets - liability;
}

double breakEvenPrice(double totalFixedCost, double unitVolume, double variableCost) {
  return (totalFixedCost / unitVolume) + variableCost;
}

double breakEvenUnits(double totalFixedCost, double salesPrice, double variableCost) {
  double den = salesPrice - variableCost;
  
  return totalFixedCost / den;
}

double simpleInterest(double principal, double rate, double time) {
  return principal * rate * time;
}

double compoundInterest(double initialPrincipal, double rate, double interest, double time) {
  double res0 = (rate / interest) + 1;
  double res1 = pow(res0, (interest * time));
  
  return initialPrincipal * res1;
}

double profitMargin(double profit, double revenue) {
  return (profit / revenue) * 100;
}

double netIncome(double revenue, double totalCost) {
  return revenue - totalCost;
}

double burnRatePercentage(double totalCost, double totalRevenue) {
  return totalCost / totalRevenue;
}

double chart[4];

double* fiftyThirtyTwenty(double revenue) {
  double needs = revenue * 0.5;
  double wants = revenue * 0.3;
  double save = revenue * 0.2;

  chart[0] = revenue;
  chart[1] = needs;
  chart[2] = wants;
  chart[3] = save;
  
  return chart;
}

double ruleOf72(double interestRate) {
  return 72 / interestRate;
}

double ruleOf25(double annualCosts) {
  return annualCosts * 25;
}

double fourPercentWithdrawl(double nestEgg) {
  return 0.04 * nestEgg;
}

double averageNetIncome(double grossIncome, double taxes) {
  return grossIncome - taxes;
}

double hoursOfLifeAsMoneyFormal(double annualGrossIncome, double taxes, double daysWorked, double hoursWorked) {
  double annualNetIncome = annualGrossIncome - taxes;
  double averageYearHoursWorked = daysWorked * hoursWorked;

  return annualNetIncome / averageYearHoursWorked;
}

double hoursOfLifeAsMoneyReal(double annualGrossIncome, double taxes, double jobRelatedCosts, double daysWorked, double hoursWorked, double extraWorkHours) {
  double annualNetIncome = annualGrossIncome - taxes;
  double totalIncome = annualNetIncome - jobRelatedCosts;
  double averageYearHoursWorked = daysWorked * hoursWorked;
  double totalHoursWorked = averageYearHoursWorked + extraWorkHours;

  return totalIncome / totalHoursWorked;
}

double purchaseAsHoursOfLifeEquivilent(double moneySpent, double realHourlyRate) {
  return moneySpent / realHourlyRate;
}

double lifetimeWealthRatio(double netWorth, double totalLifetimeIncome) {
  return netWorth / totalLifetimeIncome;
}
