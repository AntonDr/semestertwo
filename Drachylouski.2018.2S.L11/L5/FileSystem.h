#pragma once

#include <iostream>
#include <fstream>

using namespace std;

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
char* InitArray(char*);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);
void AddFile(char *, char *);
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

	int count = 0;
	char temp;

	while (!streamIn.eof())
	{
		streamIn >> temp;
		count++;
	}
	streamIn.close();
	return count;
}

char* InitArray(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	char* arr = new char[ContentsFile(fileName)];
	streamIn.getline(arr, 256);
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

void AddFile(char * fileName, char * source)
{
	ofstream streamOut(fileName, ios::app);
	
	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\nSorted string!\n";
	streamOut.width(5);
	streamOut<<source;
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