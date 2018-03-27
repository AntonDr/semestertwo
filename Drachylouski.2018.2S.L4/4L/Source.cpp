#include "ArrayLibrary.h"
#include "JaggedMatrix.h"

using namespace std;

int main()
{
	int n = 120;
	Array<int> * obj = CreateArrayOfObject(n);

	SortArray(obj,n);

	for (int i = 0; i < n; i++)
	{
		cout << obj[i].AverageSum() << endl;
	}

	system("pause");
	return 0;
}