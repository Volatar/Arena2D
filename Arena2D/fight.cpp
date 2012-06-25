#include "fight.h"

int fight(Actor player, Actor enemy)
{
	player.currentHealth = player.currentHealth - (enemy.offense - player.defense);
	enemy.currentHealth = enemy.currentHealth - (player.offense - enemy.defense);

	//check for result of exchange
	if ( (enemy.currentHealth <= 0) && (player.currentHealth >= 0) )
		return 2; //win
	if (player.currentHealth <= 0)
		return 3; //lose
	else
		return 1; //continue fighting
	// return 0 reserved for errors
}