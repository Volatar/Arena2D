#include "enemy.h"


enemy::enemy(void)
{

}

enemy::enemy(int lvl)
{
	level = lvl;
	health = //some math here
	currentHealth = health;

	offense = lvl * 5;
	defense = lvl * 5;
}

enemy::~enemy(void)
{
}
