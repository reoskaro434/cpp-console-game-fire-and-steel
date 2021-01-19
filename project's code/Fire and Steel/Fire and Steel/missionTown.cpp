#include <iostream>
#include "missionTown.h"
#include "defineThings.h"

void missionTown::show_mission_description()
{
	std::cout << "Tutejszy kowal znalazl latwy sposob na przerobienie narzedzi na bron." << std::endl;
	std::cout << "Jezeli masz przy sobie " << amountOfTools << " narzedzi to mozesz zarobic." << std::endl;
}

void missionTown::show_reward()
{
	std::cout << "Gratulacje, otrzymujesz: " << amountOfTools * townRewardPerItem << " zlota." << std::endl;
}

void missionTown::reward_the_player(character & aCharacter)
{
	show_reward();
	aCharacter.aItems.set_gold(aCharacter.aItems.get_gold() + (amountOfTools * townRewardPerItem));
	aCharacter.aItems.set_tools(aCharacter.aItems.get_tools() - amountOfTools);
}
void missionTown::do_mission(character & aCharacter)
{
	system("CLS");

	amountOfTools = (rand() % townMaxWoodAmmount) + 1;

	show_mission_description();

	system("pause");

	if (aCharacter.aItems.get_tools() >= amountOfTools)
		reward_the_player(aCharacter);
	else std::cout << "Los Ci nie sprzyja. Nie mozesz wykonac zadania." << std::endl;

	system("pause");
}
