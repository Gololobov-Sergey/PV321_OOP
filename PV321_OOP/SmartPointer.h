#pragma once


template<class T>
class SmartPointer
{
	T* ptr;

public:
	SmartPointer(T* ptr = nullptr) :ptr(ptr) {}

	~SmartPointer()
	{
		delete ptr;
	}


	SmartPointer(const SmartPointer& s)
	{
		ptr = new T;
		*ptr = *s.ptr;
	}

	SmartPointer& operator=(const SmartPointer& s)
	{
		if (&s == this)
			return *this;

		delete ptr;

		ptr = new T;
		*ptr = *s.ptr;

		return *this;
	}

	SmartPointer(SmartPointer&& s)
	{
		ptr = s.ptr;
		s.ptr = nullptr;
	}

	SmartPointer& operator=(SmartPointer&& s)
	{
		if (&s == this)
			return *this;

		delete ptr;

		ptr = s.ptr;
		s.ptr = nullptr;

		return *this;
	}


	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

};

