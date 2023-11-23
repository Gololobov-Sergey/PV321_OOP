#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

#define NOT_FOUND -1

using namespace std;


template<class T>
class List;

template<class T>
ostream& operator<<(ostream& out, const List<T>& list);


template<class T>
class List
{
	Node<T>* first = nullptr;
	Node<T>*  last = nullptr;
	size_t    size = 0;

	Node<T>* getNode(size_t index) const;

public:
	List();
	List(initializer_list<T> list);
	~List();
	List(const List<T>& fl);
	List<T>& operator=(const List<T>& fl);
	List<T> operator+(const List<T>& fl);
	void operator+=(const List<T>& fl);

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);

	T& front();
	T& back();
	T& at(size_t index) const;

	T& operator[](size_t index) const;

	void clear();
	size_t length() const;
	bool isEmpty() const;

	friend ostream& operator<< <T> (ostream& out, const List<T>& list);

	void printReverse() const;

	void unique();
	void swap(List<T>& list);

	int find(const T& value);
};

template<class T>
Node<T>* List<T>::getNode(size_t index) const
{
	Node<T>* pos;
	if (index < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < index - 1; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - index; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List()
{
}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push_back(elem);
	}
}

template<class T>
List<T>::~List()
{
	this->clear();
}

template<class T>
inline List<T>::List(const List<T>& fl)
{
	Node<T>* temp = fl.first;
	for (size_t i = 0; i < fl.size; i++)
	{
		this->push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& fl)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		first->prev = new Node<T>(value);
		first->prev->next = first;
		first = first->prev;
	}
	size++;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}

	if (index == 0)
	{
		this->push_front(value);
	}
	else if (index == size)
	{
		this->push_back(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* pos = this->getNode(index);
		newNode->next = pos->next;
		newNode->next->prev = newNode;
		newNode->prev = pos;
		pos->next = newNode;
		size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size == 0) 
	{
		return;
	}

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = nullptr;
	}
	size--;
}

template<class T>
void List<T>::pop_back()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
}

template<class T>
void List<T>::remove(size_t index)
{
	assert(index >= 0 && index < size);
	if (index == 0)
	{
		this->pop_front();
	}
	else if (index == size - 1)
	{
		this->pop_back();
	}
	else
	{
		Node<T>* temp = this->getNode(index + 1);
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		size--;
	}
}

template<class T>
T& List<T>::front()
{
	assert(size > 0);
	return first->value;
}

template<class T>
T& List<T>::back()
{
	assert(size > 0);
	return last->value;
}

template<class T>
T& List<T>::at(size_t index) const
{
	assert(size > 0);
	return this->getNode(index + 1)->value;
}

template<class T>
T& List<T>::operator[](size_t index) const
{
	return this->at(index);
}

template<class T>
void List<T>::clear()
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
inline size_t List<T>::length() const
{
	return size;
}

template<class T>
bool List<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void List<T>::printReverse() const
{
	Node<T>* temp = last;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template<class T>
void List<T>::unique()
{
	/*for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (this->operator[](i) == this->operator[](j)) 
			{
				this->remove(j);
				j--;
			}
		}
	}*/

	Node<T>* current = first;
	while (current)
	{
		Node<T>* beg = current;
		while (beg)
		{
			if (beg->next != nullptr)
			{
				if (current->value == beg->next->value)
				{
					Node<T>* del = beg->next;
					beg->next = beg->next->next;
					delete del;
					size--;
				}
				else
				{
					beg = beg->next;
				}
			}
			else
			{
				last = beg;
				break;
			}
		}
		current = current->next;
	}

}

template<class T>
inline int List<T>::find(const T& value)
{
	//

	return NOT_FOUND;
}

template<class T>
ostream& operator<<(ostream& out, const List<T>& list)
{
	Node<T>* temp = list.first;
	while (temp)
	{
		out << temp->value;
		//temp->value->print();
		temp = temp->next;
	}
	cout << endl;
	return out;
}