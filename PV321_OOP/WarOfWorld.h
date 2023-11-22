#pragma once
#include<iostream>
#include<iomanip>
#include"List.h"

using namespace std;

class Warrior
{
	int hp;
	int damage;

public:
	Warrior(int hp, int damage) : hp(hp), damage(damage) {}
	virtual ostream& print(ostream& out) const
	{
		out << "HP : " << setw(3) << hp << ", Damage : " << setw(3) << damage << endl;
		return out;
	}

	virtual void skill() = 0;

};


ostream& operator<<(ostream& out, const Warrior* w)
{
	return w->print(out);
}


class Alive : public Warrior
{
public:
	Alive(int hp, int damage) : Warrior(hp, damage) {}
};

class Dead : public Warrior
{
public:
	Dead(int hp, int damage) : Warrior(hp, damage) {}
};


class Archer : public Alive
{
public:
	Archer(int hp, int damage) : Alive(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Archer : ";
		return Warrior::print(out);
	}
};

class Swordsman : public Alive
{
public:
	Swordsman(int hp, int damage) : Alive(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Swordsman : ";
		return Warrior::print(out);
	}
};

class Rider : public Alive
{
public:
	Rider(int hp, int damage) : Alive(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Rider : ";
		return Warrior::print(out);
	}
};

class Ork : public Dead
{
public:
	Ork(int hp, int damage) : Dead(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Ork : ";
		return Warrior::print(out);
	}
};

class Zombi : public Dead
{
public:
	Zombi(int hp, int damage) : Dead(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Zombi : ";
		return Warrior::print(out);
	}
};

class Skeleton : public Dead
{
public:
	Skeleton(int hp, int damage) : Dead(hp, damage) {}
	virtual void skill() override {}
	virtual ostream& print(ostream& out) const override
	{
		out << setw(12) << "Skeleton : ";
		return Warrior::print(out);
	}
};


class WarOfWorld
{
	List<Alive*> alives;
	List<Dead*> deads;
	int count;

	Warrior* fight(Warrior* w1, Warrior* w2);

public:
	WarOfWorld(int count) : count(count) { init(); }
	void init();
	void game();
};

inline Warrior* WarOfWorld::fight(Warrior* w1, Warrior* w2)
{
	
	return nullptr;
}

void WarOfWorld::init()
{
	Alive* alive = nullptr;
	for (size_t i = 0; i < count; i++)
	{
		int rnd = rand() % 3;
		switch (rnd)
		{
		case 0: alive = new Archer(rand() % 31 + 70, rand() % 11 + 20); break;
		case 1: alive = new Swordsman(rand() % 31 + 70, rand() % 11 + 20); break;
		case 2: alive = new Rider(rand() % 31 + 70, rand() % 11 + 20); break;
		}
		alives.push_back(alive);
	}

	Dead* dead = nullptr;
	for (size_t i = 0; i < count; i++)
	{
		int rnd = rand() % 3;
		switch (rnd)
		{
		case 0: dead = new Ork(rand() % 31 + 70, rand() % 11 + 20); break;
		case 1: dead = new Zombi(rand() % 31 + 70, rand() % 11 + 20); break;
		case 2: dead = new Skeleton(rand() % 31 + 70, rand() % 11 + 20); break;
		}
		deads.push_back(dead);
	}
}

void WarOfWorld::game()
{
	do
	{
		system("cls"); cout << "--- Alives ---" << endl;
		cout << alives << endl;
		cout << endl;

		cout << "--- Deads ----" << endl;
		cout << deads << endl;
		cout << endl;

		int ind1 = rand() % alives.length();
		int ind2 = rand() % deads.length();

		Warrior* lose = fight(alives[ind1], deads[ind2]);

		if (lose == alives[ind1])
		{
			alives.remove(ind1);
		}
		else if (lose == deads[ind2])
		{
			deads.remove(ind2);
		}

		Sleep(1000);
	} while (!alives.isEmpty() && !deads.isEmpty());



}
