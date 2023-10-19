#include<iostream>

#include"Student.h"
#include"Time.h"

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


	//{
	//	Student s("Oleg", 20, 55);
	//	cout << Student::getCount() << endl;
	//	Student s1(0);
	//	cout << Student::getCount() << endl;
	//	s1.print(); // print(s1)
	//	s1.setAge(20);
	//	s1.setName("Petro");
	//	s.print();
	//	s1.print();
	//	cout << s.getCount() << endl;
	//	cout << Student::getCount() << endl;

	//	Student sss = s.get(); //get(s)
	//}
	//cout << Student::getCount() << endl;

	/*Time t1;
	Time t2(20);
	Time t3(20, 20);
	Time t4(15, 200, 15);

	t1.print();
	t2.print();
	t3.print();
	t4.print();

	t4.setSecond(59);
	t4.print();*/


	const Time t4(19, 20, 15);
	t4.print();
	cout << t4.getHour() << endl;
	cout << t4.getSecond() << endl;

	/*int a = 5.2;
	int b(5.2);
	int c{ 5 };*/


	/*std::cout << s.getName() << endl;
	cout << s.getAge() << endl;*/
}