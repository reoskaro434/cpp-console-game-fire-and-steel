#include "prepareToFight.h"
#include "items.h"


prepareToFight::prepareToFight()
{
	this->realFightingNumb = 0;
}

int& prepareToFight::get_real_fight_numb()
{
	return realFightingNumb;
}

void prepareToFight::prepare_warriors(int &munition, int &army)
{
	realFightingNumb = 0;
	while (munition > 0 and army > 0)
	{
		munition--;
		army--;
		realFightingNumb++;
	}
}

void prepareToFight::disarm_warriors(items & aItems)
{
	while (realFightingNumb>0)
	{
		realFightingNumb--;
		aItems.set_munition(aItems.get_munition() + 1);
		aItems.set_army(aItems.get_army() + 1);
	}
}

