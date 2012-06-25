#include "Actor.h"


Actor::Actor(void)
{
	level = 1;
	xp = 0;

	str = 70;
	con = 80;
	agi = 90;

	health = 30 + (level * 3) + (con / 10);
	currentHealth = health;
	
	offense = level * 10;
	defense = level * 5;
}

void Actor::setLevel(int lvl)
{
	level = lvl;
	xp = 0;

	str = 50;
	con = 60;
	agi = 70;

	health = 30 + (level * 3) + (con / 10);
	currentHealth = health;

	offense = lvl * 10;
	defense = lvl * 5;
}

Actor::~Actor(void)
{
}
