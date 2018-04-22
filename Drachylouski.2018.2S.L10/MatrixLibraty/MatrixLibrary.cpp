#include "stdafx.h"
#include "MatrixLibrary.h"
#include <cmath>
#include <iostream>
#include <exception>

using namespace std;

#pragma region Constructor

MatrixTool::Matrix::Matrix(int n, int m)
{
	this->SetHeigth(n);
	this->SetWidth(m);
	this->InitValueMatrix(0);
}

MatrixTool::Matrix::Matrix(int ** matrix, int n, int m)
{
	this->CopyMatrix(matrix);
	this->SetHeigth(n);
	this->SetWidth(m);
}

//MatrixTool::Matrix::Matrix(int n, int m, int criterion)
//{
//	this->SetHeigth(n);
//	this->SetWidth(m);
//	this->InitRandomMatrix(criterion);
//}

MatrixTool::Matrix::Matrix(const Matrix & other)
{
	this->SetHeigth(other.Height());
	this->SetWidth(other.Width());
	this->CopyMatrix(other.matrix);
}

//MatrixTool::Matrix::Matrix(int n, int m, double eps)
//{
//
//	this->SetHeigth(n);
//	this->SetWidth(m);
//	this->InitMatrixEps(eps);
//
//}
#pragma endregion

#pragma region Destructor
MatrixTool::Matrix::~Matrix()
{

	for (int i = 0; i < this->n; i++)
	{
		delete[] this->matrix[i];
	}

	delete matrix;
}
#pragma endregion

#pragma region InitMatrix

//MATRIXLIBRARY_API void MatrixTool::Matrix::InitMatrix()
//{
//	this->matrix = AllocateMemory(this->Height(), this->Width());
//	for (int i = 0; i < this->Height(); i++)
//	{
//		for (int j = 0; j < this->Width(); j++)
//		{
//			if (i == j)
//			{
//				this->matrix[i][j] = (cos(i + j) + 2 * i - j) / (i + j + 1) / (i + j + 1);
//			}
//			else
//			{
//				this->matrix[i][j] = double(i - j);
//			}
//		}
//	}
//
//}

MATRIXLIBRARY_API void MatrixTool::Matrix::InitValueMatrix(int value)
{
	this->matrix = AllocateMemory(this->Height(), this->Width());

	for (int i = 0; i < this->Height(); i++)
	{
		for (int j = 0; j < this->Width(); j++)
		{
			this->matrix[i][j] = value;
		}
	}
}

//MATRIXLIBRARY_API void MatrixTool::Matrix::InitMatrixEps(double accurancy)
//{
//	OutOfRangeExeption(accurancy);
//	this->matrix = AllocateMemory(this->Height(), this->Width());
//	for (int i = 0; i < this->Height(); i++)
//	{
//		for (int j = 0; j < this->Width(); j++)
//		{
//			if (i == j)
//			{
//				this->matrix[i][j] = (CosTaylor(i + j, accurancy) + 2 * i - j) / (i + j + 1) / (i + j + 1);
//			}
//			else
//			{
//
//				this->matrix[i][j] = i - j;
//			}
//		}
//	}
//}

MATRIXLIBRARY_API void MatrixTool::Matrix::InitRandomMatrix(int criterion)
{
	this->matrix = AllocateMemory(this->Height(), this->Width());

	for (int i = 0; i < this->Height(); i++)
	{
		for (int j = 0; j < this->Width(); j++)
		{
			this->matrix[i][j] = rand() % criterion - criterion / 2;
		}
	}

}




#pragma endregion

#pragma region Get-accessors
inline MATRIXLIBRARY_API int MatrixTool::Matrix::Height() const
{
	return this->n;
}

inline MATRIXLIBRARY_API int MatrixTool::Matrix::Width() const
{
	return this->m;
}

#pragma endregion

#pragma region Set-accessors

inline MATRIXLIBRARY_API void MatrixTool::Matrix::SetHeigth(int n)
{
	OutOfRangeExeption(n);

	this->n = n;
}

inline MATRIXLIBRARY_API void MatrixTool::Matrix::SetWidth(int m)
{
	OutOfRangeExeption(m);

	this->m = m;
}

MATRIXLIBRARY_API void MatrixTool::Matrix::CopyMatrix(int ** firstmatrix)
{
	int n = this->Height(), m = this->Width();

	this->matrix = AllocateMemory(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(*this)[i][j] = firstmatrix[i][j];
		}
	}

}
#pragma endregion

inline MATRIXLIBRARY_API int * MatrixTool::Matrix::operator[](int i)
{
	return this->matrix[i];
}

MATRIXLIBRARY_API int MatrixTool::Matrix::FindMinInRegion(int i, int j)
{
	int itemp = 0, jtemp = 0, min = 0;
	int n = this->Height();

	if (i + j < n - 1)
	{
		itemp = jtemp = i + j;
		min = (*this)[i][j];

		for (int k = 0; k <= itemp; k++, jtemp--)
		{
			for (int q = 0; q <= jtemp; q++)
			{
				if (min > (*this)[k][q])
				{
					min = (*this)[k][q];
				}
			}
		}
	}
	else if (i + j > n - 1)
	{
		itemp = abs(i + j - n + 1);
		jtemp = n - 1;
		min = (*this)[i][j];

		for (int k = (itemp); k <= n - 1; k++, jtemp--)
		{
			for (int q = jtemp; q <= n - 1; q++)
			{
				if (min > (*this)[k][q])
				{
					min = (*this)[k][q];
				}
			}
		}

	}
	else if (j + i == n - 1)
		min = (*this)[i][j];

	return min;
}

MATRIXLIBRARY_API void MatrixTool::Matrix::Display()
{
	for (int i = 0; i < this->Height(); i++)
	{
		for (int j = 0; j < this->Width(); j++)
		{
			cout.width(4);
			cout << this->matrix[i][j];

		}
		cout << endl;
	}
}

MATRIXLIBRARY_API  MatrixTool::Matrix MatrixTool::Matrix::BuildNewMatrix()
{
	Matrix obj(this->Height(), this->Width());

	int n = this->Height(), m = this->Width();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			obj[i][j] = this->FindMinInRegion(i, j);
		}
	}

	return obj;
}



int ** MatrixTool::Matrix::AllocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimention of array can not be negative or zero!");
	}

	int ** a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	return a;
}

//double MatrixTool::Matrix::CosTaylor(int value, double accurancy)
//{
//	OutOfRangeExeption(accurancy);
//
//	double term = 1, sum = 0;
//
//	int k = 0;
//
//	double a = double(value) - 2 * 3.14159265359*k;
//
//	while (a > 0)
//	{
//		k++;
//		a = double(value) - 2 * 3.14159265359*k;
//	}
//
//	for (int i = 1; fabs(term) > accurancy; i++)
//	{
//		sum += term;
//		term = -term * a*a / (2 * i) / (2 * i - 1);
//	}
//
//	return sum;
//}

//MATRIXLIBRARY_API double MatrixTool::MaxDifference(MatrixTool::Matrix &matrixone, MatrixTool::Matrix & matrixtwo)
//{
//	double max = 0;
//
//	for (int i = 0; i < matrixone.Height(); i++)
//	{
//		for (int j = 0; j < matrixone.Width(); j++)
//		{
//			if (fabs(matrixone[i][j] - matrixtwo[i][j]) > max)
//			{
//				max = fabs(matrixone[i][j] - matrixtwo[i][j]);
//			}
//		}
//
//	}
//
//	return max;
//}

#pragma region Exeption

void MatrixTool::OutOfRangeExeption(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("N can not be negative or zero!");
	}

}

template <typename T>
void MatrixTool::BadAllocate(T ** n)
{
	if (n == nullptr)
	{
		throw std::invalid_argument("Matrix can not be empty!");
	}
}

#pragma endregion
