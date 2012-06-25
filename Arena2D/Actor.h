#pragma once

#include "projectincludes.h"

class Actor
{
public:
	Actor(void);
	Actor(int);
	~Actor(void);
	
	int level;
	int xp;
	int health;
	int currentHealth;

	int str;
	int con;
	int agi;

	int offense;
	int defense;

	//TODO: Equipment (weapon and armor and magical items)
	//TODO: Inventory (array of equipment objects?)
};

