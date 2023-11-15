#pragma once
#include<string>
#include"List.h"
#include"BTree.h"

using namespace std;


class Protocol
{
	string numTZ;
	string date;
	int sum;

public:

	string getNumTZ();
	friend ostream& operator<<(ostream& out, const Protocol* p);
	friend istream& operator>>(istream& in, Protocol* p);

};


string Protocol::getNumTZ()
{
	return numTZ;
}


ostream& operator<<(ostream& out, const Protocol* p)
{
	out << p->numTZ << " " << p->date << " " << p->sum << endl;
	return out;
}

istream& operator>>(istream& in, Protocol* p)
{
	cout << "Num TZ : "; getline(in, p->numTZ);
	cout << "Date   : "; getline(in, p->date);
	cout << "Sum    : "; in >> p->sum;
	in.ignore();
	return in;
}

class BasePolice
{
	BTree<string, List<Protocol*>> base;

public:
	void addProtocol();
	void printAll();
	void printTZ();
	void printDiapTZ();

};

void BasePolice::addProtocol()
{
	system("cls");
	cout << "Add protocol" << endl;
	cout << "----------------" << endl;
	Protocol* p = new Protocol;
	cin >> p;
	List<Protocol*>* list = base.getValue(p->getNumTZ());
	if (list)
	{
		list->push_back(p);
	}
	else
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumTZ(), newList);
	}
}

void BasePolice::printAll()
{
	base.print();
	cout << endl;
	system("pause");
}
