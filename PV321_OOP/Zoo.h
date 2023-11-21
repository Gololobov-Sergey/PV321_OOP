#pragma once
#include<iostream>

using namespace std;

class Animal
{
	string name;
	int age;

public:
	Animal(string n, int a) :name(n), age(a) 
	{ 
		//cout << voice() << endl; 
	}

	virtual ~Animal() {}

	virtual string getType() { return "Animal"; }

	virtual string voice() { return ".........."; }
};



class Cat /*final*/: public Animal
{
	int* mouse;

public:
	Cat(string n, int a) : Animal(n, a) { mouse = new int[5]; }

	~Cat() 
	{ 
		cout << "Des Cat" << endl;
		delete[] mouse; 
	}

	virtual string getType() override { return "Cat"; }

	virtual string voice() override /*final*/ { return "Mau Mau"; }
};

class SiamCat : public Cat
{


public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override { return "SiamCat"; }

	//virtual string voice() { return "Myau Myau"; }
};



class Dog : public Animal
{


public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() { return "Dog"; }

	virtual string voice() { return "Gaw Gaw"; }
};