#include <iostream>
#include "gameEvent.h"
#include "pawn.h" 
#include "keyboardControls.h"
#include "map.h"
#include "placesList.h"
#include "statistics.h"
#include "places.h"
#include "character.h"



void gameEvent::do_event(character &aCharacter, map &aMap, keyboardControls &aKeyboardControls,placesList &aPlacesList)
{
	aKeyboardControls.set_pressed_key();

	switch (aKeyboardControls.get_enum_key())
	{
	case keyboardControls::moveKeyUp:
	{
		aCharacter.move_up(aMap);
	}break;
	case keyboardControls::moveKeyDown:
	{
		aCharacter.move_down(aMap);
	}break;
	case keyboardControls::moveKeyLeft:
	{
		aCharacter.move_left(aMap);
	}break;
	case keyboardControls::moveKeyRight:
	{
		aCharacter.move_right(aMap);
	}break;
	case keyboardControls::keySpace:
	{
		aCharacter.sleep();
	}break;
	case keyboardControls::keyE:
	{
		go_to_place(aPlacesList, aCharacter);
	}break;
	case keyboardControls::keyEsc:
	{
	exit_game(aKeyboardControls);
	}break;
	case keyboardControls::keyI:
	{
		aCharacter.show_character_items();
	}break;
	default:
	{

	}break;
	}

	aKeyboardControls.clear_buffor();
}

void gameEvent::go_to_place(placesList & aPlacesList, character & aCharacter)
{
	places *placeToGo = aPlacesList.find_place(aCharacter.get_obiect_coordinates(), aPlacesList.get_places_head());
	if (placeToGo != nullptr and placeToGo->aItems.get_army() > 0) 
		placeToGo->show_menu(aCharacter);
	else if(placeToGo->aItems.get_army() <= 0)
	{
		std::cout << "Miejsce zostalo zniszczone." << std::endl;
		system("pause");
	}
}

void gameEvent::exit_game(keyboardControls &aKeyboardControls)
{
	aKeyboardControls.set_end_loop(true);
}



