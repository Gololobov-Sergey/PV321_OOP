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
	//Student(Student&& obj);

	Student& operator=(const Student& obj);
	//Student& operator=(Student&& obj);
	
	~Student();

	void setAge(int age);

	int getAge();

	void setName(const char* n);

	char* getName();

	void print() const;

	Student get();

	int getGroup();

	static int getCount();

	friend ostream& operator<<(ostream& out, const Student& f);

	bool operator<(const Student& s) const;



};

class StudentNameComp
{
public:
	bool operator()(Student& s1, Student& s2)
	{
		return strcmp(s1.getName(), s2.getName()) < 0;
	}
};

class StudentAgeComp
{
public:
	bool operator()(Student& s1, Student& s2)
	{
		return s1.getAge() < s2.getAge();
	}
};
