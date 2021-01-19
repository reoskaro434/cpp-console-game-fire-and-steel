#ifndef  _RECON_H_
#define _RECON_H_

#include "arcadeGame.h"
#include "character.h"
#include "items.h"

class recon
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	arcadeGame aArcadeGame;//Allows to play arcade game.

	/************************************************* PRIVATE METHODS *************************************************/

	//Shows all element of variable aItems.
	void show_for_good(items aItems);

	//Shows items without army.
	void show_for_normal(items aItems);

	//Shows only basic items (wood, iron etc)
	void show_for_bad(items aItems);
	

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Makes arcade game, where player (aCharacter) can roll his luck. Then shows items which comes from obiect. Ammount of items which function showing depends on luck.
	void do_recon(items &aItemsFromPlace, character &aCharacter);
};

#endif