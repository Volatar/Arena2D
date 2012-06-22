#pragma once
class player
{
public:
	player(void);
	~player(void);

	int level;
	int xp;
	int health;
	int currentHealth;

	// stats
	int str;
	int con;
	int agi;

	int offense;
	int defense;

	//TODO: Equipment (weapon and armor and magical items)
	//TODO: Inventory (array of equipment objects?)

};
