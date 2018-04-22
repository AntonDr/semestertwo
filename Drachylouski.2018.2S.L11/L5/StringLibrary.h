#pragma once

#include <iostream>
#include <stdexcept>

void StrDel(char *, const char *);

void SortByAlphabet(char *);

char ** CreateArrayOfWords(const char *, int &);

void Swap(char * &, char * &);

void ArrayOfWordToString(char **,char *, int);

void Validate(char *);


void StrDel(char * source, const char * needfind)
{
	Validate(source);
	//Validate(needfind);
	

	int n = 0;

	char ** needfindarr = CreateArrayOfWords(needfind, n);

	char *result = new char[strlen(source)+1];

	char *supp = new char[strlen(source) + 1];

	for (int i = 0; i < n; i++)
	{
		while (strstr(source, needfindarr[i]) != nullptr)
		{
			
			supp = strstr(source, needfindarr[i]);

			result = strchr(supp, int(' '));

			if (!(strlen(source) - strlen(supp)))
			{
				strcpy(source, "");
				strcat(source, result+sizeof(char));
			}
			else
			{
				source[strlen(source) - strlen(supp)] = '\0';
				if (result == NULL)
				{
					strcat(source, " ");
				}
				else strcat(source, result + sizeof(char));
			}

		}

	}
}

void SortByAlphabet(char * source)
{
	Validate(source);

	int n = 0;

	char ** matrix = CreateArrayOfWords(source, n);

	bool flag = true;

	while (flag)
	{
		flag = false;


		for (int i = 0; i < n - 1; i++)
		{
			if (strcmp(matrix[i], matrix[i + 1]) > 0)
			{
				Swap(matrix[i], matrix[i + 1]);
				flag = true;
			}

		}
	}

	ArrayOfWordToString(matrix,source, n);

	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
}

char ** CreateArrayOfWords(const char * source, int & i)
{
	//Validate(source);

	char ** matrixofwords = new char *[strlen(source) / 2];

	char * supp = new char[strlen(source)];
	
	strcpy(supp, source);

	char  * pch = strtok(supp, " ,.-:;");

	i = 0;

	while (pch != nullptr)
	{
		matrixofwords[i] = new char[strlen(pch) + 1];

		strcpy(matrixofwords[i], pch);

		pch = strtok(nullptr, " ,.-:;");

		i++;
	}

	return matrixofwords;
}

void Swap(char * & a , char * & b)
{
	char * temp = a;
	a = b;
	b = temp;
}

void ArrayOfWordToString(char ** matrix,char *source, int n)
{
	Validate(source);
//	Validate(matrix);

	int lenght = 0;

	for (int i = 0; i < n; i++)
	{
		lenght += strlen(matrix[i]);
	}

	lenght++;

	source[0] = '\0';

	for (int i = 0; i < n; i++)
	{

		strcat(source, matrix[i]);
		strcat(source, " ");
	}

}

void Validate(char * source)
{
	if (source==nullptr)
	{
		throw exception("woot! a nullptr!");
	}
}

void Validate(const char * source)
{
	if (source == nullptr)
	{
		throw exception("woot! a nullptr!");
	}
}

void Validate(char ** source)
{
	if (source == nullptr)
	{
		throw exception("woot! a nullptr!");
	}
}