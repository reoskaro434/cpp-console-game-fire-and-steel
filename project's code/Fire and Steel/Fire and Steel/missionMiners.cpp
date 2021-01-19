#include <iostream>
#include "missionMiners.h"
#include "defineThings.h"

void missionMiners::show_mission_description()
{
	std::cout << "W kopalni ciagle potrzebujemy drewna." << std::endl;
	std::cout << "Jezeli masz przy sobie " << amountOfWood << " drewna, to nasze prace pojda o wiele sprawniej." << std::endl;
}

void missionMiners::show_reward()
{
	std::cout << "Gratulacje, otrzymujesz: " << amountOfWood * minersRewardPerItem << " zlota." << std::endl;
}

void missionMiners::reward_the_player(character & aCharacter)
{
	show_reward();
	aCharacter.aItems.set_gold(aCharacter.aItems.get_gold() + (amountOfWood * minersRewardPerItem));
	aCharacter.aItems.set_wood(aCharacter.aItems.get_wood() - amountOfWood);
}
void missionMiners::do_mission(character & aCharacter)
{
	system("CLS");

	amountOfWood = (rand() % minersMaxWoodAmmount) + 1;

	show_mission_description();

	system("pause");

	if (aCharacter.aItems.get_wood() >= amountOfWood)
		reward_the_player(aCharacter);
	else std::cout << "Los Ci nie sprzyja. Nie mozesz wykonac zadania." << std::endl;

	system("pause");
}
