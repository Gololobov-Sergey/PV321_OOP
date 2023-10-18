#include "Student.h"
#include<iostream>

using namespace std;

Student::Student()
{
	cout << "Constructor" << endl;
	age = 0;
	name = new char[8] {"No name"};
}

Student::Student(const char* n, int a)
{
	cout << "Constructor 2 param" << endl;
	setAge(a);
	setName(n);
}

Student::~Student()
{
	cout << "Destructor " << name << endl;
	delete[] name;
}

void Student::setAge(int a)
{
	if (a < 0 || a > 120)
		age = 0;
	age = a;
}

int Student::getAge()
{
	return age;
}

void Student::setName(const char* n)
{
	int len = strlen(n);
	delete[] name;
	name = new char[len + 1];
	strcpy_s(name, len + 1, n);
}

char* Student::getName()
{
	return name;
}

void Student::print()
{
	cout << "Name : " << name << endl;
	cout << "Age  : " << age << endl;
}
