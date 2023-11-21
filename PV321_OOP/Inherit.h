#pragma once
#include<iostream>

using namespace std;

class Human
{
	string name;
	int age;

public:
	Human() {}

	Human(string n, int a) : name(n), age(a)
	{
		cout << "H" << endl;
	}

	/*void setName(string n)
	{
		name = n;
	}*/

	string getName()
	{
		return name;
	}

	void print()
	{
		cout << "Name   : " << name << endl;
		cout << "Age    : " << age << endl;
	}
};


class FootballPlayer : public Human
{

	int games;

public:
	FootballPlayer(string n, int a, int g) : Human(n, a), games(g)
	{
		//setName(n);
		cout << "FP" << endl;
	}

	void print()
	{
		
		Human::print();
		cout << "Games  : " << games << endl;
	}
};


class Goalkeeper : public FootballPlayer
{
	int goals;

public:
	Goalkeeper(string n, int a, int g, int go) : FootballPlayer(n, a, g), goals(go)
	{
		cout << "GK" << endl;
	}

	void print()
	{
		FootballPlayer::print();
		cout << "Goals  : " << goals << endl;
	}
};


class A
{
private:
	int a1;
	void a_1() {}

protected:
	int a2;
	void a_2() {}

public:
	int a3;
	void a_3() {}
};


class B : private A
{
public:
	void b1()
	{
		//a1 = 4;
		a2 = 5;
		a3 = 9;
		a_2();
		a_3();
	}
};

class C : public  B
{
public:
	void c1()
	{
		//a2 = 9;
		//a_2();
		//a_3();
	}
};


class Device
{

};



class WiFi : public Device
{
	int id;
	//

public:
	WiFi(int id): id(id){ }
	int getID() { return id; }
	//
};

class Router : public Device
{
	int id;
	//

public:
	Router(int id) : id(id) { }
	int getID() { return id; }
	//
};

class WiFiRouter : public WiFi, public Router
{

public:
	WiFiRouter(int idWiFi, int idRouter) : WiFi(idWiFi), Router(idRouter) {	}
};