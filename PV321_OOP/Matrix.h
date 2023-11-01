#pragma once
#include<iostream>

using namespace std;

template<class T>
class Matrix;


template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& m);


template<class T>
class Matrix
{
	T** arr;
	int row;
	int col;

public:
	Matrix();
	Matrix(int row, int col);
	~Matrix();
	Matrix(const Matrix& obj);
	Matrix& operator=(const Matrix& obj);

	void copy(const Matrix& obj);

	void set();
	void setRandom(int min = 0, int max = 9);

	friend ostream& operator<< <T>(ostream& out, const Matrix<T>& m);

	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator/(const Matrix& m);
	Matrix operator*(T value);

	Matrix transpon();

	T maxValue();
	T minValue();

	//[]
};

template<class T>
Matrix<T>::Matrix() : arr(nullptr), row(0), col(0) 
{
}

template<class T>
inline Matrix<T>::Matrix(int row, int col) : row(row), col(col)
{
	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[col];
	}
}

template<class T>
inline Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<class T>
inline Matrix<T>::Matrix(const Matrix& obj)
{
	copy(obj);
}

template<class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj)
		return *this;

	copy(obj);

	return *this;
}

template<class T>
inline void Matrix<T>::copy(const Matrix<T>& obj)
{
	~Matrix();

	row = obj.row;
	col = obj.col;
	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[col];
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = obj.arr[i][j];
		}
	}
}

template<class T>
inline void Matrix<T>::set()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
}

template<class T>
inline void Matrix<T>::setRandom(int min, int max)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

template<class T>
ostream& operator<< <T>(ostream& out, const Matrix<T>& m)
{
	for (size_t i = 0; i < m.row; i++)
	{
		for (size_t j = 0; j < m.col; j++)
		{
			out << m.arr[i][j] << " ";
		}
		out << endl;
	}
	return out;
}