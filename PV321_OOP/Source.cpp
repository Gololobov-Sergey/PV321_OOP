#include<iostream>
#include<Windows.h>

#include"Student.h"
#include"Time.h"
#include"Array.h"
#include"String.h"
#include"Friend.h"
#include"Fraction.h"
#include"StaticArray.h"

using namespace std;

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}


void lucky()
{
	char pib[][50] = { 
		"Вітренко Дмитро",
		"Калатур Марк", 
		"Супруненко Ярослав", 
		"Резніченко Ангеліна", 
		"Федосеєв Владислав", 
		"Андрієвський В'ячеслав", 
		"Ващенко Владислав", 
		"Проценко Роман" };
	srand(time(0));
	int hardRoulette = rand() % 8;
	cout << "Student: " << pib[hardRoulette] << endl;
}


void PrintStudent(Student st)
{
	st.print();
}

template<class T>
void PrintArray(Array<T> a)
{
	a.print();
}

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
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//lucky();

	//////// 01.11.2023  /////////

	/*Student s1("Oleg", 20, 999);
	cout << s1 << endl;*/

	/*Array<Fraction> a(10);
	a.set(65, 120);
	a.print();*/


	//////// 31.10.2023  /////////

	/*Student s1("Oleg", 20, 999);
	s1.print();
	Student s2(s1);
	s2 = s1;
	s2.print();*/

	//Fraction f1(1, 3);
	//float f = f1;
	//cout << f << endl;
	//Student st = f1;
	//st.print();

	//Fraction f2;
	//cin >> f2;
	//cout << f2 << endl;
	//f2(4, 7); // f2.oper()(4,7)
	//cout << f2 << endl;




	/*Array<int> a(10);
	a.set(65, 80);
	a.print();
	cout << a[3] << endl;
	cout << a["one"] << endl;*/

	//////// 26.10.2023  /////////


	// - , ++ , -- , 
	// = , + , - , * , / , % , += .....
	// ! , < , > , == , != , <= , >= 
	// () , [] , (type)
	// ?: , . , sizeof , :: , 

	//Fraction f1(1, 3);
	//Fraction f2(2, 5);
	////Fraction f3 = f2.add(f1);
	////Fraction f3 = f2 + 10; //f2.op+(10);
	//Fraction f3 = 10 + f2; //10.op+(f2);
	//f3.display();
	//(f3++).display(); // f3.operator++();
	//f3.display();

	//f3 += f2;  //f3.op+=(f2)

	//int a = 5;
	//cout << ++a << endl;  // 6
	//cout << a << endl;    // 6
	//cout << a++ << endl;  // 6
	//cout << a << endl;    // 7

	//if (f1 == f2)
	//{
	//	cout << "yes" << endl;
	//}
	//else
	//{
	//	cout << "no" << endl;
	//}



	//Temperature t(25);
	//Humidity h(40);

	////WeatherInformer(t, h);

	//WeatherInformer w;
	//w.info(t, h);



	//////// 24.10.2023  /////////

	

	//String s("mama");
	//s.copy("lwkejfwe");
	//s.print();

	/*Array a(10);
	a.set();
	a.print();
	PrintArray(a);
	a.print();*/

	/*Time t;
	Time t1(3);
	Time t2(4, 3);
	Time t3(3, 5, 7);

	t.getHour();*/


	/*Student s("Oleg", 20, 321);
	s.print();
	PrintStudent(s);
	s.print();*/


	//Point p;
	/*p.x = 10;
	p.y = 20;*/
	//p.print();
	

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


	/*const Time t4(19, 20, 15);
	t4.print();
	cout << t4.getHour() << endl;
	cout << t4.getSecond() << endl;*/

	/*int a = 5.2;
	int b(5.2);
	int c{ 5 };*/


	/*std::cout << s.getName() << endl;
	cout << s.getAge() << endl;*/
}