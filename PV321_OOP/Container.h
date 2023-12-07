#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <list>

using namespace std;

template<class T>
class my_vector : public vector<T>
{
public:
	void print()
	{
		for (auto i = this->begin(); i != this->end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
};


class vectorInt : public vector<int>
{

};


template<class T>
class my_stack : public stack<T>
{
public:
	void print()
	{
		deque<T> s = this->c;
		for (auto i = s.begin(); i != s.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
};


template<class T>
T index(std::list<T>& l, int ind)
{
	return *(next(l.begin(), ind));
}