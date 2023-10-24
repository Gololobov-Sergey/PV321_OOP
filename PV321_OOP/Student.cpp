#include "Student.h"
#include<iostream>

using namespace std;

int Student::count = 0;

//Student::Student(int g) : group(g), age{0}
//{
//	cout << "Constructor" << endl;
//	name = new char[8] {"No name"};
//	count++;
//}

Student::Student(const char* n, int a, int g) : group(g)
{
	cout << "Constructor 2 param" << endl;
	this->setAge(a);
	this->setName(n);
	count++;
}

Student::Student(const Student& obj) : group(obj.group)
{
	this->age = obj.age;
	this->setName(obj.name);
	count++;
	cout << "Constructor copy" << endl;
}

Student::~Student()
{
	count--;
	cout << "Destructor " << name << endl;
	delete[] name;
}

void Student::setAge(int age)
{
	if (age < 0 || age > 120)
		this->age = 0;
	this->age = age;
}

int Student::getAge()
{
	return this->age;
}

void Student::setName(const char* n)
{
	int len = strlen(n);
	delete[] name;
	this->name = new char[len + 1];
	strcpy_s(name, len + 1, n);
}

char* Student::getName()
{
	return name;
}

void Student::print()
{
	cout << "Name   : " << name << endl;
	cout << "Age    : " << age << endl;
	cout << "Group  : " << group << endl;
}

Student Student::get()
{
	return *this;
}

int Student::getGroup()
{
	return group;
}

int Student::getCount()
{
	return count;
}
