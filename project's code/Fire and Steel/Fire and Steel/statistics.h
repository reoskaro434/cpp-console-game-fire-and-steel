#ifndef  _STATISTICS_H_
#define _STATISTICS_H_




class statistics
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	int survivedDays;//Stores survived days.

	int moveAmount;//Total left move ammount.
	
public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets moveAmount to const value and survivedDays to 0. 
	statistics();

	//Sets moveAmount to const value.
	void refresh_move_amount();

	//Returns move ammount.
	int get_move_amount();
	
	//Returns false if can't move. Decrease move ammount.
	bool decrease_move();

	//Shows move ammount and survived days.
	void show_move_ammount_and_survived_days();

	//Increases survived days.
	void increase_survived_days();
	
	//Returns survived days.
	int get_survived_days();

};

#endif 