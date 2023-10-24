#pragma once


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

