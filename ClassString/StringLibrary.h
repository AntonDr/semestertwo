#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

class String
{
	friend ostream &operator<<(ostream &, const String &);
	friend istream &operator>>(istream &, String &);
public:

	String(const char *);

	String(const String &);

	~String();

	int Length() const;

	char * GetString() const;

	bool IsEmpty() const;

	String operator+(const String &);

	String operator+=(const String &);

	const String &operator=(const String &);

	bool operator==(const String &) const;

	bool operator>(const String &) const;

	bool operator<(const String &) const; 

	bool operator<=(const String &) const;

	bool operator>=(const String &) const;
	
	char &operator[](int);

private:
	char * str;

	bool flag;

	void SetString(const char *);

	static char * AllocateMemory(const char *);
};

#pragma region Constructor & Destructor

String::String(const char * str)
{
	SetString(str);
}

String::String(const String & str)
{
	this->SetString(str.GetString());
}

String::~String()
{
	delete[] str;
}

#pragma endregion

#pragma region PrivateMethods

void String::SetString(const char * str)
{
	if (str == nullptr)
	{
		throw std::invalid_argument("");
	}

	if (flag==true)
	{
		delete[]this->str;
	}
	this->str = AllocateMemory(str);

	flag = true;

	strcpy(this->str, str);
}

char * String::AllocateMemory(const char * str)
{
	if (str == nullptr)
	{
		throw std::invalid_argument("String can't be null");
	}

	return new char[strlen(str) + 1];
}

#pragma endregion

#pragma region PublicMethods

inline int String::Length() const
{
	return strlen(this->str);
}

char * String::GetString() const
{
	char * temp = new char[Length() + 1];
	strcpy(temp, str);
	return temp;
}

inline bool String::IsEmpty() const
{
	return this->Length() == 0;
}

String String::operator+(const String & str)
{
	char * temp = new char[this->Length() + str.Length() + 1];

	strcpy(temp, "");
	strcpy(temp, this->GetString());
	strcat(temp, str.GetString());

	return String(temp);
}

String String::operator+=(const String & str)
{
	char * temp = new char[this->Length() + str.Length() + 1];

	strcpy(temp, "");
	strcpy(temp, this->GetString());
	strcat(temp, str.GetString());
	this->SetString(temp);
	return *this;
}

inline bool String::operator==(const String & str) const
{
	return strcmp(this->GetString(), str.GetString()) == 0;
}

inline const String & String::operator=(const String & str)
{
	if (this->str != str.str)
	{
		strcpy(this->str, str.GetString());
		return *this;
	}
	else return *this;
}

inline bool String::operator>(const String & str) const
{
	return strcmp(this->GetString(), str.GetString()) < 0;
}

inline bool String::operator<(const String & str) const
{
	return strcmp(this->GetString(), str.GetString()) > 0;
}

inline bool String::operator<=(const String & str) const
{
	return strcmp(this->GetString(), str.GetString()) <= 0;
}

inline bool String::operator>=(const String & str) const
{
	return strcmp(this->GetString(), str.GetString()) >= 0;
}

inline char & String::operator[](int i)
{
	return str[i];
}




#pragma endregion


ostream & operator<<(ostream & output, const String & str)
{
	output << str.GetString();
	return output;
}

istream & operator>>(istream & input, String & str)
{
	char  temp[200];

	input >> temp;
	str = temp;

	return input;
}






