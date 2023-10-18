#include<iostream>

#include"Student.h"

using namespace std;


class Point
{

	int x;
	int y;

public:
	void print()
	{
		cout << x << " " << y << endl;
	}
};

int main()
{
	//Point p;
	/*p.x = 10;
	p.y = 20;*/
	//p.print();
	
	srand(time(0));
	int hardRoulette = rand() % 8;
	cout << "Student: " << hardRoulette << endl;


	{
		Student s("Oleg", 20);
		Student s1;
		s1.print();
		s1.setAge(20);
		s1.setName("Petro");
		s.print();
		s1.print();
	}



	/*std::cout << s.getName() << endl;
	cout << s.getAge() << endl;*/
}