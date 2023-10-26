#pragma once
#include<iostream>

using namespace std;



class Humidity;
class Temperature;

class WeatherInformer
{
	int id;

public:

	void info(Temperature t, Humidity h);

	void infoDisplay(Temperature t, Humidity h);

};

class Temperature
{
	int temp;

public:
	Temperature(int t) : temp(t)
	{

	}

	void print()
	{
		cout << "Temp : " << temp << (char)248 << "C" << endl;
	}

	//friend void WeatherInformer(Temperature t, Humidity h);

	//friend class WeatherInformer;

	friend void WeatherInformer::info(Temperature t, Humidity h);
};


class Humidity
{
	int humidity;

public:
	Humidity(int h) : humidity(h)
	{

	}

	void print()
	{
		cout << "Hum  : " << humidity << "%" << endl;
	}

	//friend void WeatherInformer(Temperature t, Humidity h);

	//friend class WeatherInformer;

	friend void WeatherInformer::info(Temperature t, Humidity h);
};


//void WeatherInformer(Temperature t, Humidity h)
//{
//	cout << "Temperature : " << t.temp << (char)248 << "C" << endl;
//	cout << "Humidity    : " << h.humidity << "%" << endl;
//}



void WeatherInformer::info(Temperature t, Humidity h)
{
	cout << "Temperature : " << t.temp << (char)248 << "C" << endl;
	cout << "Humidity    : " << h.humidity << "%" << endl;
}

void WeatherInformer::infoDisplay(Temperature t, Humidity h)
{
	//cout << "Temperature : " << t.temp << (char)248 << "C" << endl;
	//cout << "Humidity    : " << h.humidity << "%" << endl;
}