F64 LoanAmort(F64 initialPrincipal, F64 periodicInterestRate, F64 numberOfPayments)
{
	F64 num = Pow(1 + periodicInterestRate, numberOfPayments) * periodicInterestRate;
	F64 den = Pow(1 + periodicInterestRate, numberOfPayments) - 1;

	F64 quo = num / den;

	return quo * initialPrincipal;
}

F64 TotalAssets(F64 equity, F64 liabilities)
{
	return equity + liabilities;
}

F64 NetWorth(F64 assets, F64 liability)
{
	return assets - liability;
}

F64 BreakEvenPrice(F64 totalFixedCost, F64 unitVolume, F64 variableCost)
{
	return (totalFixedCost / unitVolume) + variableCost;
}

F64 BreakEvenUnits(F64 totalFixedCost, F64 salesPrice, F64 variableCost)
{
	F64 den = salesPrice - variableCost;
	return totalFixedCost / den;
}

F64 SimpleInterest(F64 principal, F64 rate, F64 time)
{
	return principal * rate * time;
}

F64 CompoundInterest(F64 initialPrincipal, F64 rate, F64 interest, F64 time)
{
	F64 res0 = (rate / interest) + 1;
	F64 res1 = Pow(res0, (interest * time));

	return initialPrincipal * res1;
}

F64 ProfitMargin(F64 profit, F64 revenue)
{
	return (profit / revenue) * 100;
}

F64 NetIncome(F64 revenue, F64 totalCost)
{
	return revenue - totalCost;
}

F64 BurnRatePercentage(F64 totalCost, F64 totalRevenue)
{
	return totalCost / totalRevenue;
}

F64 chart[4];

F64* FiftyThirtyTwenty(F64 revenue)
{
	F64 needs = revenue * 0.5;
	F64 wants = revenue * 0.3;
	F64 save = revenue * 0.2;

	chart[0] = revenue;
	chart[1] = needs;
	chart[2] = wants;
	chart[3] = save;
}

F64 RuleOf72(F64 interestRate)
{
	return 72 / interestRate;
}

F64 RuleOf25(F64 annualCosts)
{
	return annualCosts * 25;
}

F64 FourPercentWithdrawl(F64 nestEgg)
{
	return 0.04 * nestEgg;
}

F64 AverageNetIncome(F64 grossIncome, F64 taxes)
{
	return grossIncome - taxes;
}

F64 HoursOfLifeAsMoneyFormal(F64 annualGrossIncome, F64 taxes, F64 daysWorked, F64 hoursWorked)
{
	F64 annualNetIncome = annualGrossIncome - taxes;
	F64 averageYearHoursWorked = daysWorked * hoursWorked;

	return annualNetIncome / averageYearHoursWorked;
}

F64 HoursOfLifeAsMoneyReal(F64 annualGrossIncome, F64 taxes, F64 jobRelatedCosts, F64 daysWorked, F64 hoursWorked, F64 extraWorkHours)
{
	F64 annualNetIncome = annualGrossIncome - taxes;
	F64 totalIncome = annualNetIncome - jobRelatedCosts;
	F64 averageYearHoursWorked = daysWorked * hoursWorked;
	F64 totalHoursWorked = averageYearHoursWorked + extraWorkHours;

	return totalIncome / totalHoursWorked;
}

F64 PurchaseAsHoursOfLifeEquivilent(F64 moneySpent, F64 realHourlyRate)
{
	return moneySpent / realHourlyRate;
}

F64 LifetimeWealthRatio(F64 netWorth, F64 totalLifetimeIncome)
{
	return netWorth / totalLifetimeIncome;
}