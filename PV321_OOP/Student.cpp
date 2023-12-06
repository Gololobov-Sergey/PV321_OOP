#include "Student.h"
#include<iostream>
#include<iomanip>

using namespace std;

int Student::count = 0;

//Student::Student(int g) : group(g), age{0}
//{
//	cout << "Constructor" << endl;
//	name = new char[8] {"No name"};
//	count++;
//}

Student::Student(const char* n, int a, int g) : group(g), age(0)
{
	//cout << "Constructor 2 param" << endl;
	this->setAge(a);
	this->setName(n);
	count++;
}

Student::Student(const Student& obj) : group(obj.group)
{
	this->age = obj.age;
	this->setName(obj.name);
	count++;
	//cout << "Constructor copy" << endl;
}

//Student::Student(Student&& obj) : group(obj.group)
//{
//	cout << "Move" << endl;
//}

Student& Student::operator=(const Student& obj) 
{
	//1
	if (this == &obj)
		return *this;
	//2
	delete[] this->name;
	//3
	this->age = obj.age;
	int len = strlen(obj.name);
	this->name = new char[len + 1];
	strcpy_s(name, len + 1, obj.name);
	//4
	return *this;
}

//Student& Student::operator=(Student&& obj)
//{
//	cout << "Move=" << endl;
//	return *this;
//}

Student::~Student()
{
	count--;
	//cout << "Destructor " << name << endl;
	delete[] name;
}

void Student::setAge(int age) /*noexcept*/
{
	if (age < 0 || age > 120)
		//this->age = 0;
		throw invalid_argument("age");
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

void Student::print() const
{
	cout << "Name   : " << setw(10) << right << name << "Age    : " << setw(10) << right << age << endl;
	/*cout << "Group  : " << group << endl;*/
}

Student Student::get()
{
	return *this;
}

int Student::getGroup()
{
	return 0/*group*/;
}

int Student::getCount()
{
	return count;
}

bool Student::operator<(const Student& s) const
{
	return age < s.age;
}

ostream& operator<<(ostream& out, const Student& f)
{
	out << "Name   : " << setw(10) << left << f.name << "Age    : " << setw(10) << left << f.age << endl;
	return out;
}
