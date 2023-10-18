#pragma once

class Student
{
private:
	char* name = nullptr;
	int age;

public:

	Student();

	Student(const char* n, int a);
	
	~Student();

	void setAge(int a);

	int getAge();

	void setName(const char* n);

	char* getName();

	void print();

};

