#pragma once

template<class T, int size>
class StaticArray
{
	T arr[size];
	int length;

public:
	StaticArray() : length(size) { }

	void set(int min, int max)
	{
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

