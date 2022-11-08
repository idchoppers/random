import Finance.Formulas;

public class Test {
    public static void main(String[] args) {
	System.out.format("%.2f\n", Formulas.loanAmort(20000.00, 0.00625, 60));
	System.out.format("%.2f\n", Formulas.totalAssets(100000.00, 50000.00));
	System.out.format("%.2f\n", Formulas.netWorth(100.00, 50.00));
	System.out.format("%.2f\n", Formulas.breakEvenPrice(100000.00, 200.00, 0.4));
	System.out.format("%.2f\n", Formulas.breakEvenUnits(100000.00, 500.4, 0.4));
	System.out.format("%.2f\n", Formulas.simpleInterest(100.00, 0.07, 60));
	System.out.format("%.2f\n", Formulas.compoundInterest(100.00, 0.07, 0.09, 60));
	System.out.format("%.2f\n", Formulas.profitMargin(2000.00, 500.00));
	System.out.format("%.2f\n", Formulas.netIncome(500.00, 2000.00));
	System.out.format("%.2f\n", Formulas.burnRatePercentage(100000.00, 2000.00));
	System.out.println("START CHART");
	for(int i = 0; i < 4; i++) {
	    double[] chart = Formulas.fiftyThirtyTwenty(4000.00);
	    System.out.format("%.2f\n", chart[i]);
	}
	System.out.println("END CHART");
	System.out.format("%.2f\n", Formulas.ruleOf72(0.07));
	System.out.format("%.2f\n", Formulas.ruleOf25(20000.00));
	System.out.format("%.2f\n", Formulas.fourPercentWithdrawl(100000.00));
	System.out.format("%.2f\n", Formulas.averageNetIncome(200000.00, 25000.00));
	System.out.format("%.2f\n", Formulas.hoursOfLifeAsMoneyFormal(200000.00, 25000.00, 260, 8));
	System.out.format("%.2f\n", Formulas.hoursOfLifeAsMoneyReal(200000.00, 25000.00, 3500.00, 260, 8, 400));
	System.out.format("%.2f\n", Formulas.purchaseAsHoursOfLifeEquivilent(170.00, 16.00));
    }
}
