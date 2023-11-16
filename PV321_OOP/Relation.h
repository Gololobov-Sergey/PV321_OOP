#pragma once
#include<iostream>

using namespace std;


namespace Composition
{
	class Engine
	{
		int power;

	public:
		void start()
		{
			cout << "Engine started" << endl;
		}
	};


	class Car
	{
		Engine* engine;

	public:
		Car()
		{
			engine = new Engine;
		}

		~Car()
		{
			delete engine;
		}

		void move()
		{
			engine->start();
			cout << "Car move" << endl;
		}
	};
}


namespace Agrigation
{
	class Engine
	{
		int power;

	public:
		void setPower()
		{
			power += 5;
		}

		void start()
		{
			cout << "Engine started" << endl;
		}
	};


	class Car
	{
		Engine* engine;

	public:
		Car(Engine* en)
		{
			engine = en;
		}

		void move()
		{
			engine->start();
			cout << "Car move" << endl;
		}

		Engine* getEngine()
		{
			return engine;
		}
	};


	class STO
	{
		Engine* engine;

	public:
		void set(Engine* en)
		{
			engine = en;
		}

		void test()
		{
			engine->setPower();
		}
	};


}
