#pragma once

#include "ArrayLibrary.h"

template <typename T>
Array<int> * CreateArrayOfObject(int);

void SortArray(Array<int> *);

template <typename T>
void Swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}


Array<int> * CreateArrayOfObject(int n)
{
	Array<int> * objArray = new Array<int>[n];

	for (int i = 0; i < n; i++)
	{
		objArray[i] =Array<int>(1 +rand() % n ,1+ rand() % n) ;
	}

	return objArray;
}


void SortArray(Array<int> * objArray,int n)
{
	bool flag = true;

	while (flag)
	{
		flag = false;

		for (int i = 0; i < n-1; i++)
		{
			if (objArray[i].AverageSum() > objArray[i + 1].AverageSum())
			{
				flag = true;
				Swap(objArray[i],objArray[i+1]);
			}
		}
	}
	
}