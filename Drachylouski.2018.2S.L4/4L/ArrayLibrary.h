#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array(int,int);
	Array(int n);
	Array();
	Array(Array &);
	~Array();
	int Length();
	double AverageSum();
	
private:
	T * innerArray;
	int n;
	void SetLength(int);
	void InitRandomArray(int);
	void CopyArray(T *);
	static T * AllocateMemory(int);

};

template<typename T>
Array<T>::Array(int n,int criterion)
{
	this->SetLength(n);
	this->innerArray = AllocateMemory(this->Length());
	this->InitRandomArray(criterion);
}

template<typename T>
inline Array<T>::Array(int n)
{
	this->SetLength(n);
	this->innerArray = AllocateMemory();
}

template<typename T>
inline Array<T>::Array()
{

}

template<typename T>
Array<T>::Array(Array<T> & obj)
{
	this->SetLength(obj.Length());
	this->CopyArray(obj.innerArray);
}


template<typename T>
inline Array<T>::~Array()
{
	//delete[] this->innerArray;
}

template<typename T>
inline int Array<T>::Length()
{
	return this->n;
}

template<typename T>
inline double Array<T>::AverageSum()
{
	double avSum = 0;

	for (int i = 0; i < this->Length(); i++)
	{
		avSum += this->innerArray[i];
	}

	return avSum/this->Length();
}


template<typename T>
inline void Array<T>::SetLength(int n)
{
	if (n<=0)
	{
		throw std::out_of_range("n can't be less zero");
	}

	this->n = n;
}

template<typename T>
void Array<T>::InitRandomArray(int criterion)
{

	for (int i = 0; i < this->Length(); i++)
	{
		this->innerArray[i] = rand() % criterion - criterion/2;
	}

}

template<typename T>
inline void Array<T>::CopyArray(T * firstArray)
{

	int n = this->Length();

	this->innerArray = AllocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		this->innerArray[i] = firstArray[i];
	}
}

template<typename T>
T* Array<T>::AllocateMemory(int n)
{
	return new T[n];
}
