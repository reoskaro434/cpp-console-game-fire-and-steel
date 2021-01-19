#include <iostream>
#include "missionCastle.h"
#include "defineThings.h"

void missionCastle::show_mission_description()
{
	std::cout << "Nasi wojownicy potrzebuja szkolenia." << std::endl;
	std::cout << "Musisz wyszkolic tylu ludzi: "<<amountOfTraining << std::endl;
}

void missionCastle::reward_the_player(character & aCharacter)
{
	show_reward();
	aCharacter.aItems.set_gold(aCharacter.aItems.get_gold() + (amountOfTraining * castleReward));
}

void missionCastle::show_reward()
{
	std::cout << "Gratulacje, otrzymujesz: " << castleReward *amountOfTraining << " zlota." << std::endl;
}

void missionCastle::do_mission(character & aCharacter)
{
	system("CLS");

	condition = true;

	amountOfTraining = ((rand() % castleMaxTrainingNumber) + 1);

	int copy = amountOfTraining;

	show_mission_description();

	system("pause");
	
	system("CLS");

	while (copy > 0 and condition == true)
	{
		aArcadeGame.do_arcade_game(breakTIMEag, aCharacter.aItems.get_food());

		if (aArcadeGame.get_last_rolled_luck() < castleMinimumLuckNumber)
			condition = false;
		else
			copy--;
	}

	system("CLS");

	if (condition == false)
		std::cout << "Los Ci nie sprzyja. Nie mozesz wykonac zadania." << std::endl;
	else
		reward_the_player(aCharacter);

	system("pause");
}
