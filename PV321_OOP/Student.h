#pragma once
#include<iostream>

class Student
{
private:
	char* name;
	int age;

public:

	void setAge(int a);

	int getAge();

	void setName(const char* n);

	char* getName();
};

