#pragma once
#include<iostream>
#include<iomanip>

#include"Queue.h"

using namespace std;


enum class DEPARTMENTS
{
	GENERAL, TRANSPORT, ACCOUNTS, DIRECTOR
};

ostream& operator<<(ostream& out, const DEPARTMENTS& d)
{
	switch (d)
	{
	case DEPARTMENTS::GENERAL:   out << "Загальний"; break;
	case DEPARTMENTS::TRANSPORT: out << "Транспортний"; break;
	case DEPARTMENTS::ACCOUNTS:  out << "Бухгалтерія"; break;
	case DEPARTMENTS::DIRECTOR:  out << "Директор"; break;
	}
	return out;
}


class TaskPrint
{
	string fName;
	size_t timePrint;
	DEPARTMENTS department;

public:
	TaskPrint();

	TaskPrint(string fn, size_t t, DEPARTMENTS dept);

	DEPARTMENTS getDepartment() const;

	size_t getTimePrint() const;

	friend ostream& operator<<(ostream& out, const TaskPrint& tp);

};


TaskPrint::TaskPrint() {}


TaskPrint::TaskPrint(string fn, size_t t, DEPARTMENTS dept) :
	fName(fn), timePrint(t), department(dept) {}

DEPARTMENTS TaskPrint::getDepartment() const
{
	return department;
}

size_t TaskPrint::getTimePrint() const
{
	return timePrint;
}


ostream& operator<<(ostream& out, const TaskPrint& tp)
{
	out << setw(15) << left << tp.department << setw(12) << tp.fName
		<< setw(4) << tp.timePrint << endl;
	return out;
}


class PrintServer
{
	string ip;
	PriorityQueue<TaskPrint, DEPARTMENTS> qPrint;
	Queue<TaskPrint> qStatistics;
	TaskPrint currentTaskPrint;
	size_t leftTimePrint = 0;

public:
	PrintServer(string ip);
	void addTaskPrint(const TaskPrint& tp);
	void work();
};

PrintServer::PrintServer(string ip) :ip(ip) {}

void PrintServer::addTaskPrint(const TaskPrint& tp)
{
	qPrint.enqueue(tp, tp.getDepartment());
}

void PrintServer::work()
{

	if (!qPrint.isEmpty() && leftTimePrint == 0)
	{
		//delete currentTaskPrint;
		currentTaskPrint = qPrint.peek();
		leftTimePrint = currentTaskPrint.getTimePrint();
		qPrint.dequeue();
	}

	system("cls");
	cout << "PrintServer : " << ip << endl;
	cout << "---------------------------" << endl << endl;
	cout << "Printing :   left time - " << leftTimePrint << endl;
	if (leftTimePrint > 0)
		cout << currentTaskPrint << endl;
	else
		cout << endl;

	cout << endl;
	cout << "Waiting:" << endl;
	cout << "---------------------------" << endl;
	qPrint.print();

}

