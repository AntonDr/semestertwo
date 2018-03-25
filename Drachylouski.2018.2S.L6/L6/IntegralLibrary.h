#pragma once

#include <iostream>


#pragma region Prototype
double ExpX(double);

typedef double(*IntegralFunction)(double);

typedef double(*FormulaForSolution)(double, double, unsigned,IntegralFunction);

double SimpsonFormula(double, double, unsigned, IntegralFunction);

double LeftRectangle(double, double, unsigned, IntegralFunction);

double CalculationOfIntegrals(FormulaForSolution, IntegralFunction, double, double, double, unsigned);
#pragma endregion


#pragma region Realization
double ExpX(double x)
{
	return exp(1 / x);
}

double SimpsonFormula(double bottomPoint, double topPoint, unsigned n, IntegralFunction f)
{
	double h = (topPoint - bottomPoint) / n;

	double sum = 0, sum2 = 0, sum4 = 0;

	for (int i = 1; i < n; i += 2)
	{
		sum2 += f(bottomPoint + h * (i + 1));
		sum4 += f(bottomPoint + h * i);
	}

	sum = f(bottomPoint) + 2 * sum2 + 4 * sum4 - f(topPoint);

	return (h / 3)*sum;
}

double LeftRectangle(double bottomPoint, double	topPoint, unsigned n, IntegralFunction f)
{
	double step = (bottomPoint + topPoint) / n;

	double sum = 0;

	double t = bottomPoint;

	while (t < topPoint)
	{
		sum += f(t);
		t += step;
	}

	sum *= step;

	return sum;
}

double CalculationOfIntegrals(FormulaForSolution Formula, IntegralFunction f, double a, double b, double eps, unsigned n)
{
	double previosIntegral = 0, nextIntegral = 1;

	while (fabs(previosIntegral - nextIntegral) > eps)
	{
		previosIntegral = Formula(2, 4, n, f);
		nextIntegral = Formula(2, 4, 2 * n, f);

		n *= 2;
	}

	return Formula(2, 4, n, f);
}


#pragma endregion
