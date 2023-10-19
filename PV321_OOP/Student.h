#pragma once

class Student
{
private:

	const int group;

	char* name = nullptr;
	int   age  = 0;

	static int count;

public:

	Student(int g);

	Student(const char* n, int a, int g);
	
	~Student();

	void setAge(int age);

	int getAge();

	void setName(const char* n);

	char* getName();

	void print();

	Student get();

	int getGroup();

	static int getCount();

};


