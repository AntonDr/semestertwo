// IntegerLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IntegerLibrary.h"
#include <stdexcept>

INTEGERLIBRARY_API void ItgLib::InsertionSort(int *arr,int *arrWithValueOfFirstSymbol, int n)
{
	ThrowExeption(arr,n);

	int j = 0;

	for (int i = 1; i < n; i++)
	{
		j = i;
		while (j && (arrWithValueOfFirstSymbol[j] > arrWithValueOfFirstSymbol[j - 1]))
		{
			Swap(arr[j], arr[j - 1]);
			Swap(arrWithValueOfFirstSymbol[j], arrWithValueOfFirstSymbol[j - 1]);
			j--;
		}
	}
}

INTEGERLIBRARY_API void ItgLib::Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

INTEGERLIBRARY_API int ItgLib::IndentifyFirstSymbol(int neadIdentife)
{
	if (neadIdentife < 0)
	{
		neadIdentife = 15;
	}
	else
	{
		for (; neadIdentife > 0xF; neadIdentife >>= 4);
	}
	
	return neadIdentife;
}

INTEGERLIBRARY_API void ItgLib::DeleteRepetitiveElements(int *arr, int &n)
{
	ThrowExeption(arr,n);

	for (int  i= 0; i < n ; i++)
	{
		int check = arr[i];

		for (int j = i+1; j < n; j++)
		{
			if (arr[j] == check)
			{
				ItgLib::DeleteFromIndex(arr, n, j);
				j--;
			}
		}
	}
}

INTEGERLIBRARY_API void ItgLib::DeleteFromIndex(int *arr, int &n, int from)
{
	ThrowExeption(arr,n);

	if (from < 0 || from > n)
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	for (int *p =arr + from; p <arr +  n-1; p++)
	{
		*p = *(p+1);
	}

	--n;
}

INTEGERLIBRARY_API void ItgLib::WriteNewArray(int *arr, int *newarr, int n)
{
	ThrowExeption(arr,n);
	ThrowExeption(newarr, n);

	int j = 0;

	for (int * p = arr; p < arr + n; p++)
	{
		*(newarr + j++) = ItgLib::IndentifyFirstSymbol(*p);
	}
}

INTEGERLIBRARY_API void ItgLib::WriteNewArrayAndCutInOld(int *arr, int *newarr, int &n,char fixed)
{
	ThrowExeption(arr,n);
	ThrowExeption(newarr, n);
	ThrowExeption(fixed);

	int l = 0,j=0;

	for (int i = 0; i < n; i++)
	{
		if (ItgLib::IsThereFixedSymbol(arr[i], fixed))
		{
			newarr[j++]= arr[i];

			ItgLib::DeleteFromIndex(arr, n, i);
			
			i--;

		}
	}
}

INTEGERLIBRARY_API bool ItgLib::IsThereFixedSymbol(int checkIt, char fixed)
{
	ThrowExeption(fixed);

	int valueOfFixed = ItgLib::CharToInt(fixed);

	for (;checkIt; checkIt>>=4)
	{
		if ((checkIt&0xF)==valueOfFixed)
		{
			return true;
		}
	}

	return false;
}

INTEGERLIBRARY_API int ItgLib::CharToInt(char s)
{
	char symbolStr[] = "0123456789ABCDEF";
	for (int i = 0; i < 17; i++)
	{
		if (s == symbolStr[i]) return i;
	}
	return -1;
}

INTEGERLIBRARY_API int ItgLib::HowManyFixedInArr(int *arr, int n, char fixed)
{
	ThrowExeption(arr,n);
	ThrowExeption(fixed);

	int j = 0;

	for (int *p = arr; p < arr+ n; p++)
	{
		if (ItgLib::IsThereFixedSymbol(*p, fixed))
		{
			j++;
		}
	}

	return j;
}

#pragma region ThrowExeption

INTEGERLIBRARY_API void ItgLib::ThrowExeption(int * arr,int n)
{
	if (arr == nullptr)
	{
		throw std::bad_alloc();
	}

	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}
}

INTEGERLIBRARY_API void ItgLib::ThrowExeption(char s)
{
	if (s < 'A' || s > 'F')
	{
		throw std::out_of_range("Out of range");
	}
}

#pragma endregion
