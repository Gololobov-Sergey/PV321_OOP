#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class Array
{
	T* arr;
	size_t size;

public:
	Array();
	explicit Array(size_t size);
	Array(const Array& obj);
	~Array();
	void set(int min = 0, int max = 9) const;
	void print() const;
	void push(T value);
	void insert(T value, size_t index);
	T get(size_t index) const;
	void remove(size_t index);

	T operator[](int index);
	T operator[](const char* key);

};

template<class T>
Array<T>::Array(): arr(nullptr), size(0) { }

template<class T>
Array<T>::Array(size_t size) : size(size)
{
	arr = new T[size];
}

template<class T>
Array<T>::Array(const Array& obj)
{
	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
}

template<class T>
void Array<T>::set(int min, int max) const
{
	cout << "Set <template>" << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

template<>
void Array<double>::set(int min, int max) const
{
	cout << "Set <double>" << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min + 0.1;
	}
}

template<>
void Array<Student>::set(int min, int max) const
{
	cout << "Set <Student>" << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = Student();
	}
}

template<class T>
void Array<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
T Array<T>::get(size_t index) const
{
	assert(index < size && "Invalid index");
	return arr[index];
}

template<class T>
T Array<T>::operator[](int index)
{
	assert(index < size && "Invalid index");
	return arr[index];
}

template<class T>
T Array<T>::operator[](const char* key)
{
	if (strcmp(key, "zero") == 0)
		return arr[0];
	if (strcmp(key, "one") == 0)
		return arr[1];
	if (strcmp(key, "two") == 0)
		return arr[2];
	if (strcmp(key, "tree") == 0)
		return arr[3];
}
