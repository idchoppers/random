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

    /*
    public static void main(String[] args) {
	System.out.format("%.2f\n", loanAmort(20000.00, 0.00625, 60));
	System.out.format("%.2f\n", totalAssets(100000.00, 50000.00));
	System.out.format("%.2f\n", netWorth(100.00, 50.00));
	System.out.format("%.2f\n", breakEvenPrice(100000.00, 200.00, 0.4));
	System.out.format("%.2f\n", breakEvenUnits(100000.00, 500.4, 0.4));
	System.out.format("%.2f\n", simpleInterest(100.00, 0.07, 60));
	System.out.format("%.2f\n", compoundInterest(100.00, 0.07, 0.09, 60));
	System.out.format("%.2f\n", profitMargin(2000.00, 500.00));
	System.out.format("%.2f\n", netIncome(500.00, 2000.00));
	System.out.format("%.2f\n", burnRatePercentage(100000.00, 2000.00));
	System.out.println("START CHART");
	for(int i = 0; i < 4; i++) {
	    double[] chart = fiftyThirtyTwenty(4000.00);
	    System.out.format("%.2f\n", chart[i]);
	}
	System.out.println("END CHART");
	System.out.format("%.2f\n", ruleOf72(0.07));
	System.out.format("%.2f\n", ruleOf25(20000.00));
	System.out.format("%.2f\n", fourPercentWithdrawl(100000.00));
	System.out.format("%.2f\n", averageNetIncome(200000.00, 25000.00));
	System.out.format("%.2f\n", hoursOfLifeAsMoneyFormal(200000.00, 25000.00, 260, 8));
	System.out.format("%.2f\n", hoursOfLifeAsMoneyReal(200000.00, 25000.00, 3500.00, 260, 8, 400));
	System.out.format("%.2f\n", purchaseAsHoursOfLifeEquivilent(170.00, 16.00));
    }
    */
}
