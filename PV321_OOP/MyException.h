#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class MyException
{
	string data;
	string time;
	string file;
	string error;
	int line;

	string message;

	string path = "log.txt";

public:
	MyException(string d, string t, string f, int l, string e):
		data(d), time(t), file(f), line(l), error(e)
	{
		message = data + " | " + time + " | " + file + " | " + to_string(line) + " | " + error;
	}

	void saveLog()
	{
		ofstream out(path, ios::app);
		out << message << endl;
		out.close();
	}

	string getError()
	{
		return message;
	}
};