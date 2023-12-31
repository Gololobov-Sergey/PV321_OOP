//#pragma once
//#include<iostream>
//#include<initializer_list>
//#include<cassert>
//
//#include"Node.h"
//#include"function.h"
//#include"BusStation.h"
//
//using namespace std;
//
//template<class T>
//class Queue
//{
//	Node<T>* first = nullptr;
//	Node<T>* last = nullptr;
//	size_t   size = 0;
//
//public:
//	Queue();
//	Queue(initializer_list<T> list);
//	~Queue();
//	Queue(const Queue<T>& q);
//	Queue& operator=(const Queue<T>& q);
//	Queue operator+(const Queue<T>& q);
//	void enqueue(const T& value);
//	void dequeue();
//	T peek();
//	bool isEmpty() const;
//	size_t length() const;
//	void clear();
//	void print() const;
//	void print(int x, int y) const;
//	void printLast10(int x, int y) const;
//
//	void ring();
//
//	void for_each(void(*method)(T&));
//
//	void superMethod();
//
//};
//
//template<class T>
//Queue<T>::Queue()
//{
//}
//
//template<class T>
//Queue<T>::Queue(initializer_list<T> list)
//{
//	for (T elem : list)
//	{
//		this->enqueue(elem);
//	}
//}
//
//template<class T>
//Queue<T>::~Queue()
//{
//	this->clear();
//}
//
//template<class T>
//void Queue<T>::enqueue(const T& value)
//{
//	if (size == 0)
//	{
//		first = last = new Node<T>(value);
//	}
//	else
//	{
//		last->next = new Node<T>(value);
//		last = last->next;
//	}
//	size++;
//}
//
//template<class T>
//void Queue<T>::dequeue()
//{
//	if (size > 0)
//	{
//		Node<T>* temp = first;
//		first = first->next;
//		delete temp;
//		size--;
//		last = (size == 0) ? nullptr : last;  // ???
//	}
//}
//
//template<class T>
//T Queue<T>::peek()
//{
//	assert(size > 0);
//	return first->value;
//}
//
//template<class T>
//bool Queue<T>::isEmpty() const
//{
//	return size == 0;
//}
//
//template<class T>
//size_t Queue<T>::length() const
//{
//	return size;
//}
//
//template<class T>
//void Queue<T>::clear()
//{
//	Node<T>* temp = first;
//	while (temp)
//	{
//		first = first->next;
//		delete temp;
//		temp = first;
//	}
//	size = 0;
//}
//
//template<class T>
//void Queue<T>::print() const
//{
//	Node<T>* temp = first;
//	while (temp)
//	{
//		cout << temp->value << endl;
//		temp = temp->next;
//	}
//	cout << endl;
//
//}
//
//template<class T>
//void Queue<T>::print(int x, int y) const
//{
//	Node<T>* temp = first;
//	while (temp)
//	{
//		gotoxy(x, y);
//		cout << temp->value << endl;
//		temp = temp->next;
//		y++;
//	}
//	cout << endl;
//}
//
//template<class T>
//inline void Queue<T>::printLast10(int x, int y) const
//{
//	Node<T>* temp = first;
//	if (size <= 10)
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			gotoxy(x, y + i);
//			cout << temp->value << endl;
//			temp = temp->next;
//		}
//	}
//	else
//	{
//		gotoxy(x, y);
//		cout << "     ****** ^ ******";
//		for (size_t i = 0; i < size; i++)
//		{
//			if (i > size - 10 && i < size)
//			{
//				gotoxy(x, y + i - size + 10);
//				cout << temp->value << endl;
//			}
//			temp = temp->next;
//		}
//	}
//}
//
//template<class T>
//void Queue<T>::ring()
//{
//	/*enqueue(first->value);
//	dequeue();*/
//
//	Node<T>* temp = first;
//	first = first->next;
//	last->next = temp;
//	last = temp;
//	last->next = nullptr;
//}
//
//template<class T>
//void Queue<T>::for_each(void(*method)(T&))
//{
//	Node<T>* temp = first;
//	while (temp)
//	{
//		method(temp->value);
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//template<class T>
//void Queue<T>::superMethod()
//{
//}
//
//template<>
//void Queue<Passenger>::superMethod()
//{
//	Node<Passenger>* temp = first;
//	while (temp)
//	{
//		temp->value.incrTime();
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//
/////////////////////////
/////                  //
///// PRIORITY QUEUE   //
/////                  //
/////////////////////////
//
//template<class T, class TPri = int>
//class PriorityQueue
//{
//	Node<T, TPri>* first = nullptr;
//	Node<T, TPri>* last = nullptr;
//	size_t   size = 0;
//
//public:
//	PriorityQueue();
//	PriorityQueue(initializer_list<T> list);
//	~PriorityQueue();
//	PriorityQueue(const PriorityQueue<T, TPri>& q);
//	PriorityQueue& operator=(const PriorityQueue<T, TPri>& q);
//	PriorityQueue operator+(const PriorityQueue<T, TPri>& q);
//	void enqueue(const T& value, const TPri& priority);
//	void dequeue();
//	T peek();
//	bool isEmpty() const;
//	size_t length() const;
//	void clear();
//	void print() const;
//	void print(int x, int y) const;
//};
//
//template<class T, class TPri>
//PriorityQueue<T, TPri>::PriorityQueue()
//{
//}
//
//template<class T, class TPri>
//PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
//{
//	for (T elem : list)
//	{
//		enqueue(elem, TPri());
//	}
//}
//
//template<class T, class TPri>
//PriorityQueue<T, TPri>::~PriorityQueue()
//{
//	clear();
//}
//
//template<class T, class TPri>
//void PriorityQueue<T, TPri>::enqueue(const T& value, const TPri& priority)
//{
//	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);
//	if (size == 0)
//	{
//		last = first = newNode;
//		size++;
//		return;
//	}
//
//	if (priority <= last->priority)
//	{
//		last->next = newNode;
//		last = newNode;
//	}
//	else if (priority > first->priority)
//	{
//		newNode->next = first;
//		first = newNode;
//	}
//	else
//	{
//		Node<T, TPri>* temp = first;
//		while (priority <= temp->next->priority)
//		{
//			temp = temp->next;
//		}
//		newNode->next = temp->next;
//		temp->next = newNode;
//	}
//	size++;
//}
//
//template<class T, class TPri>
//void PriorityQueue<T, TPri>::dequeue()
//{
//	if (size > 0)
//	{
//		Node<T, TPri>* temp = first;
//		first = first->next;
//		delete temp;
//		size--;
//		last = (size == 0) ? nullptr : last;  // ???
//	}
//}
//
//template<class T, class TPri>
//T PriorityQueue<T, TPri>::peek()
//{
//	assert(size > 0);
//	return first->value;
//}
//
//template<class T, class TPri>
//bool PriorityQueue<T, TPri>::isEmpty() const
//{
//	return size == 0;
//}
//
//template<class T, class TPri>
//size_t PriorityQueue<T, TPri>::length() const
//{
//	return size;
//}
//
//template<class T, class TPri>
//void PriorityQueue<T, TPri>::clear()
//{
//	Node<T, TPri>* temp = first;
//	while (temp)
//	{
//		first = first->next;
//		delete temp;
//		temp = first;
//	}
//	size = 0;
//}
//
//template<class T, class TPri>
//void PriorityQueue<T, TPri>::print() const
//{
//	Node<T, TPri>* temp = first;
//	while (temp)
//	{
//		cout << temp->value << endl;
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//template<class T, class TPri>
//void PriorityQueue<T, TPri>::print(int x, int y) const
//{
//	Node<T, TPri>* temp = first;
//	while (temp)
//	{
//		gotoxy(x, y);
//		cout << temp->value << endl;
//		temp = temp->next;
//		y++;
//	}
//	cout << endl;
//}
//
