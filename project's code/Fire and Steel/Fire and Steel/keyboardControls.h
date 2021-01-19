#ifndef  _KEYBOARDCONTROLS_H_
#define _KEYBOARDCONTROLS_H_



class keyboardControls
{

public:

	enum keys//List of keys, which player can press.
{
	none,
	moveKey,
	moveKeyUp,
	moveKeyDown,
	moveKeyLeft,
	moveKeyRight,
	keyE,
	keyI,
	keySpace,
	keyEsc,
	one,
	two,
	three,
	four,
	five
};

private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	bool endLoop;//Breaks loop if stores true.

	keys pressedKey;//Stores currently pressed key.
	
	bool moveKeyPressed;//True if pressed key was responsible to move.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets pressedKey to none, moveKeyPressed and endLoop to false.
	keyboardControls();

	//Analyzes pressed key from keyboard and compare it. Then sets properl enum value for variable "pressedKey".
	void set_pressed_key();

	//Gets all invalid clicks. Clears buffor.
	void clear_buffor();

	//Sets pressedKey to none and moveKeyPressed to false.
	void reset_key();

	//Returns pressed key.
	int get_enum_key();

	//Returns endLoop value.
	bool check_game_loop();

	//Sets endLoop value.
	void set_end_loop(bool trueOrFalse);

};

#endif 
