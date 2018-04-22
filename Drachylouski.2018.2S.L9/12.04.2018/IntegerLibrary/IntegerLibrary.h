#pragma once

#ifdef INTEGERLIBRARY_EXPORTS
#define INTEGERLIBRARY_API __declspec(dllexport) 
#else
#define INTEGERLIBRARY_API __declspec(dllexport) 
#endif

namespace ItgLib
{
	INTEGERLIBRARY_API void InsertionSort(int *,int *, int);

	INTEGERLIBRARY_API int	IndentifyFirstSymbol(int);

	INTEGERLIBRARY_API void DeleteRepetitiveElements(int *, int &);

	INTEGERLIBRARY_API bool IsThereFixedSymbol(int,char);

	INTEGERLIBRARY_API void WriteNewArray(int *, int *, int n);

	INTEGERLIBRARY_API void Swap(int &, int&);

	INTEGERLIBRARY_API void DeleteFromIndex(int *, int &,int);

	INTEGERLIBRARY_API void WriteNewArrayAndCutInOld(int *, int *, int &,char);

	INTEGERLIBRARY_API int CharToInt(char);

	INTEGERLIBRARY_API int HowManyFixedInArr(int *, int, char);

	INTEGERLIBRARY_API void ThrowExeption(int *,int);

	INTEGERLIBRARY_API void ThrowExeption(char s);

}