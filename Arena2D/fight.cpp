#include "fight.h"

int fight(player player1, enemy enemy1)
{
	//fighting goes here

	if ( (enemy1.currentHealth <= 0) && (player1.currentHealth >= 0) )
		return 2; //win
	if (player1.currentHealth <= 0)
		return 3; //lose
	else
		return 1; //continue fighting
}