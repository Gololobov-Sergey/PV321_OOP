#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"
#include"function.h"
#include"BusStation.h"

using namespace std;


template<class T, class TPri = int>
class BaseQueue
{
protected:
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t   size = 0;

public:
	BaseQueue();
	BaseQueue(initializer_list<T> list);
	virtual ~BaseQueue();
	BaseQueue(const BaseQueue<T, TPri>& q);
	BaseQueue<T, TPri>& operator=(const BaseQueue<T, TPri>& q);
	BaseQueue<T, TPri> operator+(const BaseQueue<T, TPri>& q);
	virtual void enqueue(const T& value, const TPri& priority = TPri()) = 0;
	void dequeue();
	T peek();
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;
	void print(int x, int y) const;
	void printLast10(int x, int y) const;

	void for_each(void(*method)(T&));

	void superMethod();

};

template<class T, class TPri>
BaseQueue<T, TPri>::BaseQueue()
{
}

template<class T, class TPri>
BaseQueue<T, TPri>::BaseQueue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T, class TPri>
BaseQueue<T, TPri>::~BaseQueue()
{
	this->clear();
}

//template<class T, class TPri>
//void BaseQueue<T, TPri>::enqueue(const T& value)
//{
//	if (size == 0)
//	{
//		first = last = new Node<T, TPri>(value);
//	}
//	else
//	{
//		last->next = new Node<T, TPri>(value);
//		last = last->next;
//	}
//	size++;
//}

template<class T, class TPri>
void BaseQueue<T, TPri>::enqueue(const T& value, const TPri& priority)
{
}

template<class T, class TPri>
void BaseQueue<T, TPri>::dequeue()
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
T BaseQueue<T, TPri>::peek()
{
	assert(size > 0);
	return first->value;
}

template<class T, class TPri>
bool BaseQueue<T, TPri>::isEmpty() const
{
	return size == 0;
}

template<class T, class TPri>
size_t BaseQueue<T, TPri>::length() const
{
	return size;
}

template<class T, class TPri>
void BaseQueue<T, TPri>::clear()
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
void BaseQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl;

}

template<class T, class TPri>
void BaseQueue<T, TPri>::print(int x, int y) const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		gotoxy(x, y);
		cout << temp->value << endl;
		temp = temp->next;
		y++;
	}
	cout << endl;
}

template<class T, class TPri>
inline void BaseQueue<T, TPri>::printLast10(int x, int y) const
{
	Node<T, TPri>* temp = first;
	if (size <= 10)
	{
		for (size_t i = 0; i < size; i++)
		{
			gotoxy(x, y + i);
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
	else
	{
		gotoxy(x, y);
		cout << "     ****** ^ ******";
		for (size_t i = 0; i < size; i++)
		{
			if (i > size - 10 && i < size)
			{
				gotoxy(x, y + i - size + 10);
				cout << temp->value << endl;
			}
			temp = temp->next;
		}
	}
}


template<class T, class TPri>
void BaseQueue<T, TPri>::for_each(void(*method)(T&))
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		method(temp->value);
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void BaseQueue<T, TPri>::superMethod()
{
}

template<>
void BaseQueue<Passenger>::superMethod()
{
	Node<Passenger>* temp = first;
	while (temp)
	{
		temp->value.incrTime();
		temp = temp->next;
	}
	cout << endl;
}


///////////////////////
///                  //
///       QUEUE      //
///                  //
///////////////////////

template<class T, class TPri = int>
class Queue : public BaseQueue<T, TPri>
{

public:

	virtual void enqueue(const T& value, const TPri& priority = TPri()) override;
	void ring();
};


template<class T, class TPri>
void Queue<T, TPri>::enqueue(const T& value, const TPri& priority)
{
	if (this->size == 0)
	{
		this->first = this->last = new Node<T, TPri>(value);
	}
	else
	{
		this->last->next = new Node<T, TPri>(value);
		this->last = this->last->next;
	}
	this->size++;
}

template<class T, class TPri>
inline void Queue<T, TPri>::ring()
{
	/*enqueue(first->value);
dequeue();*/

	Node<T, TPri>* temp = this->first;
	this->first = this->first->next;
	this->last->next = temp;
	this->last = temp;
	this->last->next = nullptr;
}

///////////////////////
///                  //
/// PRIORITY QUEUE   //
///                  //
///////////////////////

template<class T, class TPri = int>
class PriorityQueue : public BaseQueue<T, TPri>
{

public:

	virtual void enqueue(const T& value, const TPri& priority) override;

};


template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, const TPri& priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);
	if (this->size == 0)
	{
		this->last = this->first = newNode;
		this->size++;
		return;
	}

	if (priority <= this->last->priority)
	{
		this->last->next = newNode;
		this->last = newNode;
	}
	else if (priority > this->first->priority)
	{
		newNode->next = this->first;
		this->first = newNode;
	}
	else
	{
		Node<T, TPri>* temp = this->first;
		while (priority <= temp->next->priority)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	this->size++;
}



