#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class Array
{
	int* arr;
	size_t size;

public:
	Array();
	Array(size_t size);
	Array(const Array& obj);
	~Array();
	void set(int min, int max);
	void print();
	void push(int value);
	void insert(int value, size_t index);
	int get(size_t index);
	void remove(size_t index);

};

Array::Array(): arr(nullptr), size(0) { }

Array::Array(size_t size) : size(size)
{
	arr = new int[size];
}

Array::Array(const Array& obj)
{
	size = obj.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

Array::~Array()
{
	delete[] arr;
}

void Array::set(int min = 0, int max = 9)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void Array::print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

inline int Array::get(size_t index)
{
	assert(index < size && "Invalid index");
	return 0;
}
