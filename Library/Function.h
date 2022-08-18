#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

template <class T>
void addElem(T*& arr, int& size, T elem)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = elem;
	size++;
	delete[] arr;
	arr = temp;
}

template <class T>
void dellElem(T*& arr, int& size, int value)
{
	T* temp = new T[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (size < (value - 1))
		{
			temp[i] = arr[i];
		}
		else if (size >= (value - 1))
		{
			temp[i] = arr[i + 1];
		}
	}
	size--;
	delete[]arr;
	arr = temp;
}
