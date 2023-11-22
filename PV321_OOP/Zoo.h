#pragma once
#include<iostream>
#include<fstream>

using namespace std;



class IPrintable
{
public:
	virtual ~IPrintable() {}
	virtual void print() = 0;

};


class Animal
{
protected:
	string name;
	int age;

public:
	Animal(string n, int a) :name(n), age(a) 
	{ 
		//cout << voice() << endl; 
	}

	virtual ~Animal() {}

	virtual string getType() { return "Animal"; }

	virtual string voice() = 0;
};

string Animal::voice()
{
	return "????????";
}

class Cat /*final*/: public Animal, public IPrintable
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

	virtual void print() override { cout << "I`m Cat " << name << endl; }
};

class SiamCat : public Cat
{


public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override { return "SiamCat"; }

	//virtual string voice() { return "Myau Myau"; }
};



class Dog : public Animal, public IPrintable
{


public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() { return "Dog"; }

	virtual string voice() { return "Gaw Gaw"; }

	virtual void print() override { cout << "I`m Dog " << name << endl; }
};

class Ulitka : public Animal
{


public:
	Ulitka(string n, int a) : Animal(n, a) {}

	virtual string getType() { return "Ulitka"; }

	virtual string voice() { return Animal::voice(); }
};


class Fish : public Animal
{


public:
	Fish(string n, int a) : Animal(n, a) {}

	virtual string getType() { return "Fish"; }

	virtual string voice() { return Animal::voice(); }
};


class ILogError
{
public:
	virtual void writeError(string message) = 0;
};


class LogErrorFile : public ILogError
{
	string fName;
public:
	LogErrorFile(string fn) : fName(fn) {}
	void writeError(string message) override
	{
		ofstream out(fName, ios::app);
		out << message << endl;
		out.close();
	}
};

class LogErrorConsole : public ILogError
{

public:
	LogErrorConsole() {}
	void writeError(string message) override
	{	
		cout << message << endl;
	}
};