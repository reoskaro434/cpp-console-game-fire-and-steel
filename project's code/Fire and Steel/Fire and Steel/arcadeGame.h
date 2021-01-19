#ifndef  _ARCADEGAME_H_
#define  _ARCADEGAME_H_

#include "keyboardControls.h"
#include "items.h"

class arcadeGame
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	keyboardControls arcadeKeyboardControls;//Alow to use keyboards.

	float lastRolledLuck;//Luck rolled in arcade game.

	int numb;//Stores generated number.

	int numbOfAttemptsPerRound;//Determinates how many times numbers will be generate(per round).

	int oneRoundCost;//How many food needs to unlock round.

	int breakTimeForNow;//Time determinates how long generated number will be exist.

	/************************************************* PRIVATE METHODS *************************************************/

	//Returns round's cost.
	int get_round_cost();

	//Returns true if foodNumber is grater or equal oneRoundCost. Substract this number of food and allows to play next round.
	bool pay_for_next_round(int &foodNumber);

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Initializes round cost and numbers of attempts per round.
	arcadeGame();

	//Generates "luck" by computer.
	void automatic_luck();

	//Returns last's rolled luck.
	float get_last_rolled_luck();

	//Starts arcade game. Break time determinates how long generated number will be exist, food number stores the numbers of obiect food.
	void do_arcade_game(const int breakTime, int &foodNumber);

};

#endif