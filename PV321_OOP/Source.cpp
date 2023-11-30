#include<iostream>
#include<Windows.h>
#include<regex>
#include<array>
#include<vector>
#include<algorithm>
#include<queue>

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
#include"Zoo.h"
#include"WarOfWorld.h"
#include"MyException.h"
#include"SmartPointer.h"
#include"TestSystem.h"
#include"Container.h"

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


void Voice(Animal* an)
{
	cout << an->voice() << endl;
}


void PlayAnimal(Animal* an)
{
	cout << an->voice() << endl;

	Cat* c = dynamic_cast<Cat*>(an);
	if(c)
		c->catchMouse();
}

void PrintDisplay(IPrintable* p)
{
	p->print();
}


double division(int a, int b, ILogError& log)
{
	if (b == 0)
	{
		log.writeError("Division by zero!");
		return 0;
	}
	log.writeError("Operation compleat!");
	return a / b;
}

void f3()
{
	cout << "Start f3" << endl;
	throw 1.3;
	cout << "End f3" << endl;
}

void f2()
{
	cout << "Start f2" << endl;
	try
	{
		f3();
	}
	catch (double d)
	{
		cout << "Double" << endl;
	}
	cout << "End f2" << endl;
}

void f1()
{
	cout << "Start f1" << endl;
	f2();
	cout << "End f1" << endl;
}


SmartPointer<Fraction> func()
{
	SmartPointer<Fraction> s(new Fraction(1, 2));

	//Fraction* f = new Fraction(1, 2);

	(*s).display();
	s->display();

	//
	//int a;
	//cin >> a;
	//if (a == 0)
	//	//throw new exception("Fatal error");
	//	return;

	

	//delete f;
	return s;
}


Student getStudent(SmartPointer<Fraction>&& sf)
{
	Student s;
	//
	return s;
}


int getIntValue(string coment)
{
	while (true)
	{
		cout << coment << " : ";
		int value;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Bat value. Reapeat enter." << endl;
		}
		else
		{
			cin.ignore(1024, '\n');
			return value;
		}
	}
}

int getIntValue2(string coment)
{
	while (true)
	{
		cout << coment << " : ";
		string value;
		getline(cin, value);
		regex r("^-*\\d+$");

		if (!regex_match(value, r))
		{
			cout << "Bat value. Reapeat enter." << endl;
		}
		else
		{
			return atoi(value.c_str());
		}
	}
}

template<class T>
void print(vector<T>& v)
{
	for (T a : v)
	{
		cout << a << " ";
	}
	cout << endl;
}

bool elemBig5(int a)
{
	return a > 5;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);

	//lucky();
	auto st = [](Student s1, Student s2) {return strcmp(s1.getName(), s2.getName()); };
	priority_queue <Student, vector<Student>, st> d;



	/*vector<int> v1;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	print(v1);*/
	my_vector<int> v1({ 1,2,3,4 });

	my_vector<int> v2({1,2,3,4});
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	print(v2);

	v2.assign({ 7,8,9,5 });
	print(v2);

	v2.push_back(99);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	print(v2);

	v2.pop_back();
	v2.pop_back();
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	print(v2);

	v2.shrink_to_fit();
	v2.push_back(99);
	v2.push_back(77);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	print(v2);
	v2.print();

	/*cout << v2[3] << endl;
	auto t = v2.begin();
	t += 3;
	cout << *t << endl;*/

	//v2.insert(v2.begin() + 2, {33,44,55});
	v2.insert(v2.cbegin() + 2, v1.begin()+1, v1.begin()+3);

	print(v2);
	v2.erase(v2.begin() + 2);
	erase(v2, 99);
	erase_if(v2, elemBig5);
	erase_if(v2, [](int a) {return a > 5; });
	v2.print();


	my_stack<int> ss;
	ss.push(100);
	ss.push(200);
	ss.push(300);
	ss.print();


	/*auto f = []() {cout << "Hello\n"; };
	f();

	auto d = [](int a)->int {
		if (a > 0)
			return 3;
		else
			return 3.5;
	};

	char sym;
	cin >> sym;
	int ff = 55, gg = 4;
	auto s = [&]() {cout << sym <<  ++ff << ++gg << endl; };
	s();*/

	/*vector<Fraction> vf;
	vf.push_back(Fraction(1, 3));
	Fraction f(1, 4);
	vf.push_back(f);
	vf.emplace_back(2, 7);
	vf.emplace(vf.begin()+2, 2, 9);
	print(vf);*/


	/*vector<int> v3(5, 9);
	cout << v3.size() << endl;
	cout << v3.capacity() << endl;
	print(v3);

	vector<int> v4(5);
	cout << v4.size() << endl;
	cout << v4.capacity() << endl;
	print(v4);

	vector<int> v5(v3);*/

	/*auto a5 = std::to_array({ std::make_unique<int>(3) });
	cout << *(a5[0].get()) << endl;*/

	/*string s;
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s = "mama";
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s += "lewiwoierwoeir";
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	s.shrink_to_fit();
	cout << s.capacity() << endl;
	cout << s.size() << endl;
	cout << s.max_size() << endl;

	s.append("kkj");*/
	

	/*App app;
	app.menu();*/

	//////// 28.11.2023  /////////

	/*cout.setf(ios::showpos);

	int t;
	t = getIntValue2("Enter temperature");
	cout << t << endl;*/


	/*string pass;
	getline(cin, pass);
	hash<string> h;
	int a = h(pass);
	cout << a << endl;*/


	/*cout << boolalpha << true << endl;
	cout << false << endl;

	cout << hex << 255 << endl;
	cout << dec << 255 << endl;
	cout << oct << 255 << endl;

	cout << dec;
	cout.setf(ios::showpos);
	cout << 255 << endl;
	cout << -255 << endl;

	cout.unsetf(ios::showpos);*/

	/*cout.setf(ios::scientific);
	cout << 123.456789 << endl;
	cout << 1234.56789 << endl;
	cout << 12345.6789 << endl;
	cout << 123456.789 << endl;
	cout << 12.3456789 << endl;
	cout << .123456789 << endl;


	cout.setf(ios::fixed, ios::floatfield);
	cout << setprecision(0) << 123.456 << endl;
	cout << setprecision(1) << 123.456 << endl;
	cout << setprecision(2) << 123.456 << endl;
	cout << setprecision(3) << 123.456 << endl;
	cout << setprecision(4) << 123.456 << endl;
	cout << setprecision(5) << 123.456 << endl;
	cout << setprecision(6) << 123.456 << endl;
	cout << setprecision(7) << 123.456 << endl;
	cout << setprecision(8) << 123.456 << endl;*/

	/*cout.fill('.');
	
	cout << setw(10) << internal << 123.32;
	cout << "Count" << endl;
	cout << setw(10) << internal << -123.32;
	cout << "Count" << endl;
	cout << setw(10) << internal << 123.32;
	cout << "Count" << endl;
	cout << setw(10) << internal << -123.32;
	cout << "Count" << endl;

	cout.width(10);
	cout << left << 12.3; cout << "Count" << endl;*/



	//unique_ptr<Fraction> f(new Fraction(1, 3));
	/*unique_ptr<Fraction> f = make_unique<Fraction>(1, 3);
	f->display();
	unique_ptr<Fraction> f1;
	f1 = move(f);
	f1->display();*/
	
	/*shared_ptr<Fraction> f = make_shared<Fraction>(1, 3);
	f->display();
	{
		shared_ptr<Fraction> f1 = f;
		f1->display();
		{
			shared_ptr<Fraction> f2 = f1;
			f2->display();
		}
		f1->display();
	}
	f->display();*/
	
	


	//SmartPointer<Fraction> s = func();

	//Student s = getStudent(SmartPointer<Fraction>(new Fraction(1, 2)));

	/*int a = 5;
	int& r = a;
	int&& s = 5;*/

	/*Fraction f(1, 2);
	Fraction& ff = f;
	Fraction&& fff = Fraction(1, 3);*/

	//////// 23.11.2023  /////////
	//cout << "Start main" << endl;
	//try
	//{

	//	//f1();

	//	int a, b;
	//	cin >> a >> b;
	//	if (b == 0)
	//		throw MyException(__DATE__, __TIME__, __FILE__, __LINE__, "arg b = 0!!");
	//	//throw "Error #123";
	//	cout << a / b << endl;
	//}
	//catch (int a)
	//{
	//	cout << "Error " << a << endl;
	//}
	//catch (const char* st)
	//{
	//	cout << "Error - " << st << endl;
	//}
	//catch (MyException& e)
	//{
	//	e.saveLog();
	//	cout << e.getError() << endl;
	//}
	//catch (...)
	//{
	//	cout << "Fatal Error" << endl;
	//}
	//cout << "End main" << endl;



	/*throw 1.5;
	throw "Error";
	throw NOT_FOUND;
	throw Fraction();*/



	/*Animal* cat = new Cat("Tom", 5);
	Animal* dog = new Dog("Patron", 5);
	PlayAnimal(dog);*/


	/*FootballPlayer p("Zidan", 50, 1000);
	p.print();
	cout << endl;

	Human h = p;
	h.print();*/

	/*WiFiRouter r(123, 456);
	cout << r.WiFi::getID() << endl;
	cout << r.Router::getID() << endl;
	cout << r.WiFi::dev << endl;
	cout << r.Router::dev << endl;*/


	//////// 22.11.2023  /////////

	//WarOfWorld war(10);
	//war.game();



	/*LogErrorFile log("log.txt");
	cout << division(45, 0, log) << endl;

	LogErrorConsole logC;
	cout << division(45, 5, logC) << endl;*/

	/*Animal a("???", 0);
	cout << a.getType() << endl;
	cout << a.voice() << endl;*/

	/*Cat* cat = new Cat("Tom", 5);
	cout << cat->voice() << endl;

	PrintDisplay(cat);


	Dog dog("Spike", 3);
	PrintDisplay(&dog);*/

	//delete cat;

	

	//////// 21.11.2023  /////////

	/*{
		Animal* cat = new Cat("Tom", 5);
		delete cat;
	}*/
	//cout << cat.getType() << endl;
	//cout << cat.voice() << endl;

	/*Dog dog("Spike", 3);
	Animal& an1 = cat;
	an1.voice();*/
	/*cout << dog.getType() << endl;
	cout << dog.voice() << endl;

	Animal& an1 = dog;
	cout << an1.getType() << endl;
	cout << an1.voice() << endl;

	Animal* an2 = &dog;
	cout << an2->getType() << endl;
	cout << an2->voice() << endl;

	cout << "-------------" << endl;

	SiamCat s_cat("Murzik", 5);
	Animal* animal[] = { &cat, &dog, &s_cat };
	for (size_t i = 0; i < 3; i++)
	{
		cout << animal[i]->getType() << endl;
		cout << animal[i]->voice() << endl;
	}
	cout << "-------------" << endl;

	Voice(&dog);
	Voice(&cat);*/


	/*WiFiRouter r(123, 456);
	cout << r.WiFi::getID() << endl;
	cout << r.Router::getID() << endl;*/


	/*Human h("Serg", 25);
	h.print();

	FootballPlayer p("Zidan", 50, 1000);
	p.print();

	Goalkeeper gk("Pyatov", 33, 200, 300);
	gk.print();


	A a;
	B b;*/
	
	

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