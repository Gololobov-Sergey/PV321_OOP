#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

using namespace std;

template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

public:
	Queue();
	Queue(initializer_list<T> list);
	~Queue();
	Queue(const Queue<T>& q);
	Queue& operator=(const Queue<T>& q);
	Queue operator+(const Queue<T>& q);
	void enqueue(const T& value);
	void dequeue();
	T peek();
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;

	void ring();


};

