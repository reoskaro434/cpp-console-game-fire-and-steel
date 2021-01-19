#ifndef  _PREPARETOFIGHT_H_
#define _PREPARETOFIGHT_H_

#include "items.h"

class prepareToFight
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	int realFightingNumb;//Stores armies who are able to fight.

public:

	/************************************************* PUBLIC METHODS *************************************************/
	
	//Sets realFightNumb to 0.
	prepareToFight();

	//Returns real fight number.
	int &get_real_fight_numb();

	//Sets real fight soldiers. Each soldier requires one munition.
	void prepare_warriors(int &munition,int &army);

	//Returns soldiers who survived war to aItems, and same number of munition.
	void disarm_warriors(items & aItems);
	
};

#endif