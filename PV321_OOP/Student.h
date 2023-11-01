#pragma once
#include<iostream>

using namespace std;

class Student
{
private:

	const int group;

	char* name = nullptr;
	int   age  = 0;

	static int count;

public:
	Student() : Student(0) {}

	Student(int g) : Student("No name", 0, g) {}

	Student(const char* n, int a, int g);

	Student(const Student& obj);

	Student& operator=(const Student& obj);
	
	~Student();

	void setAge(int age);

	int getAge();

	void setName(const char* n);

	char* getName();

	void print();

	Student get();

	int getGroup();

	static int getCount();

	friend ostream& operator<<(ostream& out, const Student& f);

};


