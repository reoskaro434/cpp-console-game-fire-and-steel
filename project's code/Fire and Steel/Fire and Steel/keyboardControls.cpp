#include "keyboardControls.h"
#include "defineThings.h"
#include <conio.h>

keyboardControls::keyboardControls()
{
	pressedKey = none;
	moveKeyPressed = false;
	endLoop = false;
}

void keyboardControls::set_pressed_key()
{
	char key = _getch();
	if (key == MOVE_KEY)
	{
		moveKeyPressed = true;

		key = _getch();

		if (key == UP)
			pressedKey = moveKeyUp;
		if (key == DOWN)
			pressedKey = moveKeyDown;
		if (key == LEFT)
			pressedKey = moveKeyLeft;
		if (key == RIGHT)
			pressedKey = moveKeyRight;
	}
	else if (key == E)
		pressedKey = keyE;
	else if (key == I)
		pressedKey = keyI;
	else if (key == SPACE)
		pressedKey = keySpace;
	else if (key == ESC)
		pressedKey = keyEsc;
	else if (key == ONE)
		pressedKey = one;
	else if (key == TWO)
		pressedKey = two;
	else if (key == THREE)
		pressedKey = three;
	else if (key == FOUR)
		pressedKey = four;
	else if (key == FIVE)
		pressedKey = five;
}

void keyboardControls::clear_buffor()
{
	reset_key();
	do {
		if (_kbhit())
		{
			_getch();
		}
	} while (_kbhit());
}

void keyboardControls::reset_key()
{
	pressedKey = none;
	moveKeyPressed = false;
}

int keyboardControls::get_enum_key()
{
	return this->pressedKey;
}

bool keyboardControls::check_game_loop()
{
	return endLoop;
}

void keyboardControls::set_end_loop(bool trueOrFalse)
{
	endLoop = trueOrFalse;
}

