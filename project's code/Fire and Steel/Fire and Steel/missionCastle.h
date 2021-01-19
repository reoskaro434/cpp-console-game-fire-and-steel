#ifndef  _MISSIONCASTLE_H_
#define _MISSIONCASTLE_H_


#include "arcadeGame.h"
#include "character.h"

class missionCastle
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	arcadeGame aArcadeGame;//Allows to play arcade game.
	
	bool condition;//Stops loop if true.

	int amountOfTraining;//Amount of training soldiers.

	/************************************************* PRIVATE METHODS *************************************************/
	
	//Shows mission's description.
	void show_mission_description();

	//Gives player (aCharacter) reward for mission.
	void reward_the_player(character & aCharacter);

	//Shows reward.
	void show_reward();

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Starts mission for player (acharacter).
	void do_mission(character & aCharacter);
};

#endif