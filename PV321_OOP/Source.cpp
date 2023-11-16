#include<iostream>
#include<Windows.h>

#include"Student.h"
#include"Time.h"
#include"Array.h"
#include"String.h"
#include"Friend.h"
#include"Fraction.h"
#include"StaticArray.h"
#include"Matrix.h"
#include"Stack.h"
#include"Calc.h"
#include"Queue.h"
#include"PrintServer.h"
#include"BusStation.h"
#include"ForwardList.h"
#include"List.h"
#include"Timer.h"
#include"BTree.h"
#include"BasePolice.h"
#include"Relation.h"
#include"Inherit.h"

using namespace std;

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


void IncTime(Passenger& p)
{
	p.incrTime();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);

	//lucky();


	Human h("Serg", 25);
	h.print();

	FootballPlayer p("Zidan", 50, 1000);
	p.print();

	Goalkeeper gk("Pyatov", 33, 200, 300);
	gk.print();


	A a;
	B b;
	
	

	/*Composition::Car car;
	car.move();

	Agrigation::Engine* en = new Agrigation::Engine;
	Agrigation::Car car1(en);
	Agrigation::STO sto;
	sto.set(car1.getEngine());
	sto.test();

	car1.move();*/


	//////// 15.11.2023  /////////

	/*BasePolice base;
	base.addProtocol();
	base.addProtocol();
	base.printAll();
	base.addProtocol();
	base.addProtocol();
	base.printAll();*/

	/*BTree<int, int> b;
	cout << b.push_r(10, 10) << endl;
	cout << b.push_r(5, 5) << endl;
	cout << b.push_r(20, 20) << endl;
	cout << b.push_r(8, 8) << endl;
	cout << b.push_r(15, 15) << endl;
	cout << b.push_r(1, 1) << endl;
	b.print();
	cout << endl;
	b.remove(10);
	b.print();*/

	//////// 14.11.2023  /////////


	/*List<int> l;
	for (size_t i = 0; i < 1000; i++)
	{
		l.push_back(rand() % 100);
	}*/
	//l.push_back(10);
	//l.push_front(20);
	//cout << l << endl;
	//l.insert(99, 4);
	//cout << l << endl;
	//l.printReverse();
	////l.pop_back();
	////l.pop_front();
	//l.remove(3);
	//cout << l << endl;
	//l.printReverse();
	//for (size_t i = 0; i < l.length(); i++)
	//{
	//	cout << l[i] << " ";
	//}
	//cout << endl;
	//cout << l << endl;
	//Timer t;
	//l.unique();
	//cout << t.elapsed() << endl;
	//cout << l << endl;


	//////// 09.11.2023  /////////


	/*ForwardList<int> fl = { 1,2,3 };
	cout << fl << endl;
	fl.push_back(44);
	cout << fl << endl;
	fl.push_front(55);
	cout << fl << endl;
	fl.insert(66, 2);
	cout << fl << endl;

	fl.pop_back();
	fl.pop_front();
	cout << fl << endl;
	fl.remove(2);
	cout << fl << endl;

	{
		ForwardList<int> fl1;
		fl1 = fl;
		cout << fl1 << endl;
	}

	cout << fl << endl;

	ForwardList<int> fl1 = { 4,5,6 };
	ForwardList<int> fl3 = fl + fl1;
	cout << "-----" << endl;
	cout << fl<< endl;
	cout << fl1<< endl;
	cout << fl3<< endl;

	fl += fl1;
	cout << "-----" << endl;
	cout << fl << endl;
	cout << fl1 << endl;
	cout << fl3 << endl;*/


	//////// 08.11.2023  /////////

	/*Queue<Passenger> q;
	q.enqueue(Passenger());
	q.enqueue(Passenger());
	q.enqueue(Passenger());
	q.enqueue(Passenger());
	q.enqueue(Passenger());
	q.enqueue(Passenger());
	q.print();
	q.for_each(IncTime);
	q.print();
	q.superMethod();
	q.print();*/




	

	/*string fn[] = { "file1.xtx", "file2.xls", "file3.doc", "file4.ppt", "file5.pdf" };


	PrintServer ps("192.168.0.201");

	int i = 0;
	while (true)
	{
		if (i % 5 == 0)
		{
			ps.addTaskPrint(
				TaskPrint(fn[rand() % 5],
				rand() % 4 + 4,
				(DEPARTMENTS)(rand() % 4)));
		}
		ps.work();
		i++;
		Sleep(1000);
	}*/


	//////// 07.11.2023  /////////

	/*PriorityQueue<int, Fraction> q;
	q.enqueue(10, Fraction(1, 2));
	q.enqueue(20, Fraction(2, 3));
	q.enqueue(30, Fraction(1, 4));
	q.enqueue(40, Fraction(1, 6));
	q.enqueue(50, Fraction(5, 2));
	q.print();*/


	/*Queue<int> q = { 5,6,7,8 };
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.print();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.print();
	q.clear();
	q.print();
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	q.enqueue(400);
	q.enqueue(500);
	q.ring();
	q.ring();
	q.print();*/


	//////// 02.11.2023  /////////


	/*Calc c("2*2^3+3");
	cout << c.getResult() << endl;*/


	/*Stack<int> st = {1,2,3,4};
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.print();
	cout << st.isEmpty() << endl;
	cout << st.peek() << endl;
	st.pop();
	st.pop();
	st.print();
	cout << st.peek() << endl;
	st.clear();
	st.print();
	cout << st.isEmpty() << endl;*/



	//////// 01.11.2023  /////////


	/*Matrix<int> m(3, 3);
	m.setRandom();
	cout << m << endl;*/


	/*Student s1("Oleg", 20, 999);
	cout << s1 << endl;*/
	

	/*Array<Fraction> a(10);
	a.set(65, 120);
	a.print();*/


	//////// 31.10.2023  /////////

	/*Student s1("Oleg", 20, 999);
	s1.print();
	//Student s2(s1);
	Student s2 = s1;
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