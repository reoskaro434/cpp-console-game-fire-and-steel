#ifndef  _MISSIONTOWN_H_
#define _MISSIONTOWN_H_


#include "arcadeGame.h"
#include "character.h"

class missionTown
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	int amountOfTools;//Stores amount of tools.

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