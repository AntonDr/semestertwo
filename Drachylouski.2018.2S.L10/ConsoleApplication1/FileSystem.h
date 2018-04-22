#pragma once

#include <iostream>
#include <fstream>
#include "MatrixLibrary.h";

using namespace std;
using namespace MatrixTool;

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char*, int);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);
void AddFile(char *, Matrix);
int ** InitMatrix(char *, int & , int &);

void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);
	//ofstream streamOut;
	//streamOut.open(fileName, ios::out);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");
	for (int i = 1; i <= n; i++)
	{
		//cout << "enter value # " << i << " : ";
		//cin >> temp;
		int temp = n - i;
		streamOut.width(5);
		streamOut << temp;
		//cout << temp << endl;
	}

	streamOut.close();
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, temp;

	while (!streamIn.eof())
	{
		streamIn >> temp;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void BubbleSort(int* arr, int n)//error dimention!
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
			}
		}
	}
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

void AddFile(char * fileName, Matrix obj)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	int n = obj.Height(), m = obj.Width();
	streamOut << "\nSorted Matrix!\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j< m; j++)
		{
			streamOut.width(5);
			streamOut << obj[i][j];
		}
		streamOut << "\n";
		
	}
	streamOut.close();
}

int ** InitMatrix(char * fileName, int & n, int & m)
{
	ifstream in(fileName);

	if (!in.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	int temp;

	while (!in.eof())
	{
		in >> temp;
		count++;
	}

	in.seekg(0, ios::beg);
	in.clear();

	int count_space = 0;
	char symbol;
	while (!in.eof())
	{
		in.get(symbol);
		if (symbol == ' ') count_space++;
		if (symbol == '\n') break;
	}

	in.seekg(0, ios::beg);
	in.clear();

	n = count / (count_space + 1);
	m = count_space + 1;

	
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			in >> matrix[i][j];
		}
	}

	return matrix;
}