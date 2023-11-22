#pragma once
#include"List.h"


class Warrior
{

};


class Alive : public Warrior
{

};

class Dead : public Warrior
{

};


class Archer : public Alive
{

};

class Swordsman : public Alive
{

};

class Rider : public Alive
{

};

class Ork : public Dead
{

};

class Zombi : public Dead
{

};

class Skeleton : public Dead
{

};


class WarOfWorld
{
	List<Alive*> alives;
	List<Dead*> deads;
	int count;

public:
	WarOfWorld(int count) : count(count) {}
	void init();
	void game();
};