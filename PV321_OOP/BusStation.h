#pragma once


class Passenger
{
	int time = 0;

public:
	int getTime()
	{
		return time;
	}

	void setTime(int t)
	{
		time = t;
	}

	void incrTime()
	{
		time++;
	}

	friend ostream& operator<<(ostream& out, const Passenger& p);
};

ostream& operator<<(ostream& out, const Passenger& p)
{
	out << p.time << endl;
	return out;
}