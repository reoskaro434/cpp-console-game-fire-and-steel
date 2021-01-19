#include <iostream>
#include "fight.h"
#include "defineThings.h"
#include "obiect.h"
#include "prepareToFight.h"


fight & fight::operator>>(obiect & anObiectShowingArmies)
{
	std::cout << anObiectShowingArmies.aPrepareToFight.get_real_fight_numb() << std::endl;

	return *this;
}

bool fight::is_end_calculate(float  aggressorLuck, int  &aggressorArmy, float  defenderLuck, int & defenderArmy)
{
	float luckBalance;
	int attackA, attackB;

	luckBalance = aggressorLuck - defenderLuck;
	if (luckBalance < 0) //Defender attack first.
	{
		luckBalance -= (2 * luckBalance); 

		attackA = luckBalance * defenderArmy;

		if (attackA == 0 && aggressorArmy > 0) aggressorArmy--;//If is one vs one.
		else aggressorArmy -= attackA;

		if (aggressorArmy <= 0)
		{
			aggressorArmy = 0;
			return true;
		}
		else
		{
			attackB = luckBalance * aggressorArmy;
			defenderArmy -= attackB;
			if (defenderArmy <= 0)
			{
				return true;
			}
			else return false;
		}
	}
	else if (luckBalance == 0)
	{
		return false;
	}
	else if (luckBalance > 0) //Aggressor attack first.
	{

		attackB = luckBalance * aggressorArmy;


		if (attackB == 0 && defenderArmy > 0) defenderArmy--;//If is one vs one. 
		else defenderArmy -= attackB;
		//If someone from obiect "b" survived.
		if (defenderArmy <= 0)
		{
			defenderArmy = 0;
			return true;
		}
		else
		{
			attackA = luckBalance * defenderArmy;
			aggressorArmy -= attackA;
			if (aggressorArmy <= 0)
			{
				aggressorArmy = 0;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void fight::show_battle_status(obiect & attacker, obiect & defender)
{
	//Showing army.
	system("cls");

	std::cout << "Pozostale wojska agresora:" << std::endl;
	*this >> attacker;
	std::cout << std::endl;

	std::cout << "Pozostale wojska obroncy:" << std::endl;
	*this >> defender;
	std::cout << std::endl;
	
	system("pause");
}

void fight::do_fight(obiect & aggressor, obiect & defender)
{
	if (!(aggressor == defender)) //Security for obiect fighting with himsefl.
	{
		bool endLoop = false;
		do {

			//Prepare wariors for fight.
			aggressor.aPrepareToFight.prepare_warriors(aggressor.aItems.get_munition(), aggressor.aItems.get_army());
			defender.aPrepareToFight.prepare_warriors(defender.aItems.get_munition(), defender.aItems.get_army());

			//Showing number of armies.
			this->show_battle_status(aggressor, defender);

			//Rolling "luck".
			if (aggressor.get_is_this_player())
				aggressor.aArcadeGame.do_arcade_game(breakTIMEag, aggressor.aItems.get_food());
			else
				aggressor.aArcadeGame.automatic_luck();

			if (defender.get_is_this_player())
				defender.aArcadeGame.do_arcade_game(breakTIMEag, defender.aItems.get_food());
			else
				defender.aArcadeGame.automatic_luck();

			//Calculateing battle.
			endLoop = is_end_calculate(aggressor.aArcadeGame.get_last_rolled_luck(), aggressor.aPrepareToFight.get_real_fight_numb(), defender.aArcadeGame.get_last_rolled_luck(), defender.aPrepareToFight.get_real_fight_numb());

			//Checking if one of army is less than 0.
			if (aggressor.aPrepareToFight.get_real_fight_numb() <= 0)
				aggressor.aItems.set_army(0);
			else if (defender.aPrepareToFight.get_real_fight_numb() <= 0)
				defender.aItems.set_army(0);


			//Disarming warriors.
			aggressor.aPrepareToFight.disarm_warriors(aggressor.aItems);
			defender.aPrepareToFight.disarm_warriors(defender.aItems);
			

		} while (endLoop == false);

	}
}

void fight::aggressor_winning_message(obiect & defeated)
{
	std::cout << "Agresor zwyciezyl, ponizej pokazano przedmioty ktore zdobyl." << std::endl;
	std::cout << std::endl;

	defeated.aItems.show_all_obiect_items();
}

void fight::defender_winning_message(obiect & defeated)
{
	std::cout << "Obronca przegonil wroga. Przeszukujac pobojowisko znaleziono takie przedmioty. " << std::endl;
	std::cout << std::endl;

	defeated.aItems.show_all_obiect_items();
}
