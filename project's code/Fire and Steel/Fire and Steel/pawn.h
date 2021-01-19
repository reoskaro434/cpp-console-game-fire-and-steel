#ifndef  _PAWN_H_
#define _PAWN_H_

#include <Windows.h>
#include "statistics.h"
#include "obiect.h"
#include "map.h"
#include "mapElement.h"



class pawn :public obiect
{
protected:

	/************************************************* PROTECTED ATTRIBUTES *************************************************/

	char pawnMark;//Stores pawn's mark.

	mapElement *addressOfStay;//Stores element's map where pawn is.

	/************************************************* PROTECTED METHODS *************************************************/

	//Sets pawn's mark to new place.
	void update_position();

	//Return true if "element's" address is walkable.
	bool can_go(mapElement *element);

public:

	/************************************************* PUBLIC ATTRIBUTES *************************************************/

	statistics aStatistic;//Stores statistics.

	static	bool scriptPlayerTurn;//Static variable. 

	/************************************************* PUBLIC METHODS *************************************************/

	//Takes pawn to up element. aMap is used to sets new addres of stay.
	void move_up(map &aMap);

	//Takes pawn to down element. aMap is used to sets new addres of stay.
	void move_down(map &aMap);

	//Takes pawn to left element. aMap is used to sets new addres of stay.
	void move_left(map &aMap);

	//Takes pawn to right element. aMap is used to sets new addres of stay.
	void move_right(map &aMap);

	//Sets addres of stay to nullptr.
	void set_address_of_stay_to_nullptr();

	//Sets address of stay to addres in function parameter.
	void set_address_of_stay(mapElement *address);

};

#endif 