// 12.04.2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "IntegerLibrary.h"
#include<fstream>
//#include <stdlib>
//#include <process>

using namespace std;
using namespace ItgLib;


void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char*, int);
char * InitArray(char *);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);
char ** ObtainWords(char *, int &);
void AddFile(char *, char **, int);

int main()
{
	/*const int N = 30;
	char fileName[N] = "";
	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');
	int n;
	cout << "Enter count of th numbers:" << endl;
	cin >> n;
	system("cls");
	CreateFile(fileName, n);
	int count = ContentsFile(fileName);
	int* array = InitArray(fileName, count);
	BubbleSort(array, count);*/
	int n = 33;
	char fixed = 'A';
	char fileName[30] = "array.txt";
	CreateFile(fileName, n);
	int count = ContentsFile(fileName);

	int * source = InitArray(fileName, count);

	int * helparr = new int[count];
	ItgLib::DeleteRepetitiveElements(source, count);
	ItgLib::WriteNewArray(source, helparr, count);

	
	ItgLib::InsertionSort(source, helparr, count);

	int *lastarr = new int[ItgLib::HowManyFixedInArr(source, count, fixed)]{ 0 };

	ItgLib::WriteNewArrayAndCutInOld(source, lastarr, count, fixed);

	for (int i = 0; i < count; i++)
	{
		cout << source[i] << " ";
	}

	AddFile(fileName, source, count);

	/*int n;
	char ** arofw = ObtainWords(array, n);
	AddFile(file,arofw ,n );*/
	/*for (int i = 0; i < count; i++)
		cout << array[i] << " ";
	for (int i = 0; i < count; i++)
		array[i] += 100;
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";*/
	//system("pause");
	return 0;
}

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

	int count = 0,temp;

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

char * InitArray(char * fileName)
{
	ifstream streamIn(fileName,ios::in);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	
	int n = ContentsFile(fileName);

	char* arr = new char[n];
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

char ** ObtainWords(char * source, int & n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	const char* symbols = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);

	n++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}

void AddFile(char *fileName, char ** arrayOfWords, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nArray of words!\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(arrayOfWords[i])+1; j++)
		{
			streamOut << arrayOfWords[i][j];
		}
		streamOut << "\n";
	}
	streamOut.close();
}
