#include <iostream>
#include "missionWoodcutters.h"
#include "defineThings.h"

void missionWoodcutters::show_mission_description()
{
	std::cout << "Potrzebujemy zelaza, abysmy mogli wykonywac narzedzia, do produkcji drewna." << std::endl;
	std::cout << "Jezeli tylko masz przy sobie " << amountOfIron <<" zelaza, to bedziemy bardzo wdzieczni."<< std::endl;
}

void missionWoodcutters::show_reward()
{
	std::cout << "Gratulacje, otrzymujesz: " << amountOfIron * woodcuttersRewardPerItem << " zlota." << std::endl;
}

void missionWoodcutters::reward_the_player(character & aCharacter)
{
	show_reward();
	aCharacter.aItems.set_gold(aCharacter.aItems.get_gold() + (amountOfIron * woodcuttersRewardPerItem));
	aCharacter.aItems.set_iron(aCharacter.aItems.get_iron() - amountOfIron);
}
void missionWoodcutters::do_mission(character & aCharacter)
{
	system("CLS");

	amountOfIron = (rand() % woodcuttersMaxIronAmmount) + 1;

	show_mission_description();

	system("pause");

	if (aCharacter.aItems.get_iron() >= amountOfIron)
		reward_the_player(aCharacter);
	else std::cout << "Los Ci nie sprzyja. Nie mozesz wykonac zadania." << std::endl;
	
	system("pause");
}
