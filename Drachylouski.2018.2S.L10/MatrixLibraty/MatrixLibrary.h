#pragma once

#ifdef MATRIXLIBRARY_EXPORTS
#define MATRIXLIBRARY_API __declspec(dllimport) 
#else
#define MATRIXLIBRARY_API __declspec(dllexport) 
#endif

namespace MatrixTool
{
	class Matrix
	{
	public:
		MATRIXLIBRARY_API Matrix(int, int);
		MATRIXLIBRARY_API Matrix(int **, int, int);
		MATRIXLIBRARY_API Matrix(const Matrix&);
		//MATRIXLIBRARY_API Matrix(int, int,double);
		MATRIXLIBRARY_API ~Matrix();
		MATRIXLIBRARY_API int Height() const;
		MATRIXLIBRARY_API int Width() const;
		MATRIXLIBRARY_API int* operator [](int);
		MATRIXLIBRARY_API void Display();
		MATRIXLIBRARY_API Matrix BuildNewMatrix();

	private:
		int ** matrix;
		int n;
		int m;
		//MATRIXLIBRARY_API void InitMatrix();
		MATRIXLIBRARY_API void InitValueMatrix(int = 0);
		MATRIXLIBRARY_API void InitRandomMatrix(int);
		MATRIXLIBRARY_API void CopyMatrix(int**);
		MATRIXLIBRARY_API int FindMinInRegion(int, int);
		//MATRIXLIBRARY_API void InitMatrixEps(double);
		MATRIXLIBRARY_API void SetHeigth(int);
		MATRIXLIBRARY_API void SetWidth(int);

		static int ** AllocateMemory(int, int);
		//static double CosTaylor(int, double);
	};

	//MATRIXLIBRARY_API double MaxDifference(Matrix &, Matrix &);

	void OutOfRangeExeption(int);
	//void OutOfRangeExeption(double);
	template <typename T>
	void BadAllocate(T **);
}