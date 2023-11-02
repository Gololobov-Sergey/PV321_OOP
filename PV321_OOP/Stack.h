#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

using namespace std;

template<class T>
class Stack
{
	Node<T>* first = nullptr;
	size_t   size  = 0;

public:
	Stack();
	Stack(initializer_list<T> list);
	~Stack();
	Stack(const Stack<T>& st);
	Stack<T>& operator=(const Stack<T>& st);

	void push(const T& value);
	const T& peek() const;
	void pop();
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;

};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::Stack(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push(elem);
	}
}

template<class T>
Stack<T>::~Stack()
{
	this->clear();
}

template<class T>
void Stack<T>::push(const T& value)
{
	if (size == 0)
	{
		first = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
const T& Stack<T>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
void Stack<T>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return first == nullptr;
}

template<class T>
size_t Stack<T>::length() const
{
	return size;
}

template<class T>
void Stack<T>::clear()
{
	/*while (first)
		this->pop();*/


	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T>
void Stack<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}



