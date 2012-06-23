#include "projectincludes.h"

player::player(void)
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


player::~player(void)
{
}
