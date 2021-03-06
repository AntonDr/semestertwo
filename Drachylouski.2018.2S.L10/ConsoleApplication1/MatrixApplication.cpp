// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "MatrixLibrary.h"
#include "FileSystem.h"

using namespace MatrixTool;
using namespace std;


int main()
{
	char fileName[30] = "matrix.txt";
	//CreateFile(fileName, 10);
	int n, m;
	int ** matrix = InitMatrix(fileName, n, m);
	
	Matrix obj(n, m, m);

	Matrix two = obj.BuildNewMatrix();

	AddFile(fileName, two);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
//	cout << endl;

	//two.Display();

	system("pause");
	
    return 0;
}

