#pragma once

#include "projectincludes.h"

class enemy
{
public:
	enemy(void);
	enemy(int);
	~enemy(void);

	int level;
	int health;
	int currentHealth;

	int offense;
	int defense;

	//TODO: Equipment
};

