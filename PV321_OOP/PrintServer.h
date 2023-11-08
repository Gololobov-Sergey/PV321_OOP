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
		<< setw(4) << tp.timePrint;
	return out;
}


class PrintServer
{
	string ip;
	PriorityQueue<TaskPrint, DEPARTMENTS> qPrint;
	Queue<TaskPrint> qStatistics;
	TaskPrint currentTaskPrint;
	size_t leftTimePrint = 0;
	size_t allTime = 0;

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
	cout << "----------------------------" << endl << endl;
	cout << "Друкується :   Залишилось часу - " << leftTimePrint << endl;
	if (leftTimePrint > 0)
		cout << currentTaskPrint << endl;
	else
		cout << endl << endl;

	cout << endl;
	cout << "Очікує :                          Надруковано:" << endl;
	cout << "----------------------------      --------------------------------" << endl;
	qPrint.print();
	qStatistics.printLast10(34, 8);

	gotoxy(0, 20);
	cout << "------------------------------------------------------------------" << endl;
	cout << "Надруковано файлів: " << setw(4) << qStatistics.length() << " Загальний час: " << allTime << endl;

	if (leftTimePrint > 0)
		leftTimePrint--;

	if (leftTimePrint == 0)
	{
		qStatistics.enqueue(currentTaskPrint);
		allTime += currentTaskPrint.getTimePrint();
	}

}

