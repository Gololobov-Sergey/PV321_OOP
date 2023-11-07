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

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T>
Queue<T>::~Queue()
{
	this->clear();
}

template<class T>
void Queue<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;  // ???
	}
}

template<class T>
T Queue<T>::peek()
{
	assert(size > 0);
	return first->value;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
size_t Queue<T>::length() const
{
	return size;
}

template<class T>
void Queue<T>::clear()
{
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
void Queue<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
	
}

template<class T>
void Queue<T>::ring()
{
	/*enqueue(first->value);
	dequeue();*/

	Node<T>* temp = first;
	first = first->next;
	last->next = temp;
	last = temp;
	last->next = nullptr;
}


///////////////////////
///                  //
/// PRIORITY QUEUE   //
///                  //
///////////////////////

template<class T, class TPri = int>
class PriorityQueue
{
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t   size = 0;

public:
	PriorityQueue();
	PriorityQueue(initializer_list<T> list);
	~PriorityQueue();
	PriorityQueue(const PriorityQueue<T, TPri>& q);
	PriorityQueue& operator=(const PriorityQueue<T, TPri>& q);
	PriorityQueue operator+(const PriorityQueue<T, TPri>& q);
	void enqueue(const T& value, const TPri& priority);
	void dequeue();
	T peek();
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;
};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
	for (T elem : list)
	{
		enqueue(elem, TPri());
	}
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	clear();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, const TPri& priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);
	if (size == 0)
	{
		last = first = newNode;
		size++;
		return;
	}

	if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		Node<T, TPri>* temp = first;
		while (priority <= temp->next->priority)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;  // ???
	}
}

template<class T, class TPri>
T PriorityQueue<T, TPri>::peek()
{
	assert(size > 0);
	return first->value;
}

template<class T, class TPri>
bool PriorityQueue<T, TPri>::isEmpty() const
{
	return size == 0;
}

template<class T, class TPri>
size_t PriorityQueue<T, TPri>::length() const
{
	return size;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
