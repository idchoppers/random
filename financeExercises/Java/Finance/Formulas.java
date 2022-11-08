package Finance;

import static java.lang.Math.pow;

public class Formulas {
    public static double loanAmort(double initialPrincipal, double periodicInterestRate, double numberOfPayments) {
	double num = Math.pow((1 + periodicInterestRate), numberOfPayments) * periodicInterestRate;
	double den = Math.pow((1 + periodicInterestRate), numberOfPayments) - 1;

	double quo = num / den;

	return quo * initialPrincipal;
    }

    public static double totalAssets(double equity, double liabilities) {
	return equity + liabilities;
    }

    public static double netWorth(double assets, double liability) {
	return assets - liability;
    }

    public static double breakEvenPrice(double totalFixedCost, double unitVolume, double variableCost) {
	return (totalFixedCost / unitVolume) + variableCost;
    }

    public static double breakEvenUnits(double totalFixedCost, double salesPrice, double variableCost) {
	double den = salesPrice - variableCost;

	return totalFixedCost / den;
    }

    public static double simpleInterest(double principal, double rate, double time) {
	return principal * rate * time;
    }

    public static double compoundInterest(double initialPrincipal, double rate, double interest, double time) {
	double res0 = (rate / interest) + 1;
	double res1 = Math.pow(res0, (interest * time));

	return initialPrincipal * res1;
    }

    public static double profitMargin(double profit, double revenue) {
	return (profit / revenue) * 100;
    }

    public static double netIncome(double revenue, double totalCost) {
	return revenue - totalCost;
    }

    public static double burnRatePercentage(double totalCost, double totalRevenue) {
	return totalCost / totalRevenue;
    }

    private static double[] chart = new double[4];
    
    public static double[] fiftyThirtyTwenty(double revenue) {
	double needs = revenue * 0.5;
	double wants = revenue * 0.3;
	double save = revenue * 0.2;

	chart[0] = revenue;
	chart[1] = needs;
	chart[2] = wants;
	chart[3] = save;

	return chart;
    }

    public static double ruleOf72(double interestRate) {
	return 72 / interestRate;
    }

    public static double ruleOf25(double annualCosts) {
	return annualCosts * 25;
    }

    public static double fourPercentWithdrawl(double nestEgg) {
	return 0.04 * nestEgg;
    }

    public static double averageNetIncome(double grossIncome, double taxes) {
	return grossIncome - taxes;
    }

    public static double hoursOfLifeAsMoneyFormal(double annualGrossIncome, double taxes, double daysWorked, double hoursWorked) {
	double annualNetIncome = annualGrossIncome - taxes;
	double averageYearHoursWorked = daysWorked * hoursWorked;

	return annualNetIncome / averageYearHoursWorked;
    }

    public static double hoursOfLifeAsMoneyReal(double annualGrossIncome, double taxes, double jobRelatedCosts, double daysWorked, double hoursWorked, double extraWorkHours) {
	double annualNetIncome = annualGrossIncome - taxes;
	double totalIncome = annualNetIncome - jobRelatedCosts;
	double averageYearHoursWorked = daysWorked * hoursWorked;
	double totalHoursWorked = averageYearHoursWorked + extraWorkHours;

	return totalIncome / totalHoursWorked;
    }

    public static double purchaseAsHoursOfLifeEquivilent(double moneySpent, double realHourlyRate) {
	return moneySpent / realHourlyRate;
    }

    public static double lifetimeWealthRatio(double netWorth, double totalLifetimeIncome) {
	return netWorth / totalLifetimeIncome;
    }
}
