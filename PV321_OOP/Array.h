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
	explicit Array(size_t size);
	Array(const Array& obj);
	~Array();
	void set(int min, int max) const;
	void print() const;
	void push(int value);
	void insert(int value, size_t index);
	int get(size_t index) const;
	void remove(size_t index);

	int operator[](int index);
	int operator[](const char* key);

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

void Array::set(int min = 0, int max = 9) const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void Array::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int Array::get(size_t index) const
{
	assert(index < size && "Invalid index");
	return arr[index];
}

inline int Array::operator[](int index)
{
	assert(index < size && "Invalid index");
	return arr[index];
}

inline int Array::operator[](const char* key)
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
