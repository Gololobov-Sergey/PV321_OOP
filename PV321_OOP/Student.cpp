#include "Student.h"

void Student::setAge(int a)
{
	if (a < 0 || a > 100)
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
	name = new char[len + 1];
	strcpy_s(name, len + 1, n);
}

char* Student::getName()
{
	return name;
}
