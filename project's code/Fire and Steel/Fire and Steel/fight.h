#ifndef  _FIGHT_H_
#define _FIGHT_H_

#include "obiect.h" 
#include "prepareToFight.h"

class fight :public prepareToFight
{
private:
	
	/************************************************* PRIVATE METHODS *************************************************/

	//Shows ammount of soldiers who can fight.
	fight & operator>>(obiect & anObiectShowingArmies);

	//Returns true if battle is end or false if one of army is not equal to 0. Calculate battle using ALuck and BLuck.
	bool is_end_calculate(float ALuck, int &AArmy, float BLuck, int &BArmy);

	//Shows for player numbers of attacker soldier and defender soldier.
	void show_battle_status(obiect & attacker, obiect & defender);
	

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Start battle between aggressor and defender
	void do_fight(obiect & aggressor, obiect & defender);

	//Shows win message for aggresor, and items from defeated obiect.
	void aggressor_winning_message(obiect &defeated);

	//Shows win message for defender, and items from defeated obiect.
	void defender_winning_message(obiect &defeated);
};

#endif 