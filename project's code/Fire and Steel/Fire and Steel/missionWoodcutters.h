#ifndef  _MISSIONWOODCUTTERS_H_
#define _MISSIONWOODCUTTERS_H_


#include "arcadeGame.h"
#include "character.h"

class missionWoodcutters
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	int amountOfIron;//Stores amount of iron.

	/************************************************* PRIVATE METHODS *************************************************/

	//Shows mission's description.
	void show_mission_description();

	//Shows reward.
	void show_reward();

	//Gives player (aCharacter) reward for mission.
	void reward_the_player(character & aCharacter);

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Starts mission for player (acharacter).
	void do_mission(character &aCharacter);
};

#endif