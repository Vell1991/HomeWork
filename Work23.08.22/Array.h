#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class Array
{
	int size;
	int* arr;

public:
	Array() : Array(5) {}
	explicit Array (int size) : size(size) 
	{
		arr = new int[size];
		SetArray();
	}
	Array(const Array& other);
	~Array() { delete[]arr; }
	int& operator[](int indx);
	int& operator[](const char* name);
	int operator()(int indx);
	operator int()const;
	void SetArray(int min = 0, int max = 9);
	void print();
};


Array::Array(const Array& other)
{
	this->size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}


int& Array::operator[](int indx)
{
	assert(indx >= 0 && indx < size);
	return this->arr[indx];
}

int& Array::operator[](const char* name)
{
	if (strcmp(name, "one") == 0)
		return arr[0];
}

int Array::operator()(int indx)
{
	for (int i = 0; i < size; i++)
	{
		this->arr[i] += indx;
	}
	return 1;
}

Array::operator int() const
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp += arr[i];
	}
	return temp;
}

void Array::SetArray(int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % max + min;
	}
}


void Array::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}




