#include "IntegralLibrary.h"

using namespace std;

int main()
{
	cout<<CalculationOfIntegrals(SimpsonFormula, ExpX, 2, 4, 0.0005, 4);

	cout << endl;

	system("pause");

	return 0;
}