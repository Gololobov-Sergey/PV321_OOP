#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "Menu.h"

using namespace std;

class User
{
public:
	virtual void menu() = 0;
};


class Admin : public User
{
public:
	void addTest();
	void editTest();

	virtual void menu() override
	{
		do
		{
			system("cls");
			cout << "Admin menu" << endl;
			int c = Menu::select_vertical({ "Add Test", "Edit Test", "Statistics", "Exit"},
				HorizontalAlignment::Center);
			switch (c)
			{
			case 0: ; break;
			case 1: ; break;
			case 2: ; break;
			case 3: return;
			}
		} while (true);
	}
};

class Student1 : public User
{
public:
	void passTest();

	virtual void menu() override
	{
		do
		{
			system("cls");
			cout << "Student menu" << endl;
			int c = Menu::select_vertical({ "Pass Test", "Statistics", "Exit" },
				HorizontalAlignment::Center);
			switch (c)
			{
			case 0:; break;
			case 1:; break;
			case 2: return;
			}
		} while (true);
	}
};

class App
{
	User* user;

	void registation();

	void login();

public:


	void menu();

};

inline void App::registation()
{
}

inline void App::login()
{
	system("cls");
	string login, pass;
	cout << "Login    : ";
	getline(cin, login);
	cout << "Password : ";
	getline(cin, pass);
	if (pass == "admin")
	{
		user = new Admin;
	}
	else
	{
		user = new Student1;
	}
	user->menu();
}

void App::menu()
{
	do
	{
		system("cls");
		int c = Menu::select_vertical({ "Registration", "Login", "Exit" },
			HorizontalAlignment::Center);
		switch (c)
		{
		case 0: registation(); break;
		case 1: login(); break;
		case 2: exit(0); break;
		}
	} while (true);
}