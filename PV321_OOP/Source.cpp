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
	Point p;
	/*p.x = 10;
	p.y = 20;*/
	p.print();
	


	Student s;
	s.setAge(20);
	s.setName("Oleg");

	cout << s.getName() << endl;
	cout << s.getAge() << endl;
}