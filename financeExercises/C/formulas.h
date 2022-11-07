#include <stdio.h>
#include <math.h>

#ifndef FORMULAS_H_INCLUDED
#define FORMULAS_H_INCLUDED

double loanAmort(double initialPrincipal, double periodicInterestRate, double numberOfPayments);
double totalAssets(double equity, double liabilities);
double netWorth(double assets, double liability);
double breakEvenPrice(double totalFixedCost, double unitVolume, double variableCost);
double breakEvenUnits(double totalFixedCost, double salesPrice, double variableCost);
double simpleInterest(double principal, double rate, double time);
double compoundInterest(double initialPrincipal, double rate, double interest, double time);
double profitMargin(double profit, double revenue);
double netIncome(double revenue, double totalCost);
double burnRatePercentage(double totalCost, double totalRevenue);
double* fiftyThirtyTwenty(double interestRate);
double ruleOf72(double revenue);
double ruleOf25(double annualCosts);
double fourPercentWithdrawl(double nestEgg);
double averageNetIncome(double grossIncome, double taxes);
double hoursOfLifeAsMoneyFormal(double annualGrossIncome, double taxes, double daysWorked, double hoursWorked);
double hoursOfLifeAsMoneyReal(double annualGrossIncome, double taxes, double jobRelatedCosts, double daysWorked, double hoursWorked, double extraHoursWorked);
double purchaseAsHoursOfLifeEquivilent(double moneySpent, double realHourlyRate);
double lifetimeWealthRatio(double netWorth, double totalLifetimeIncome);

#endif
