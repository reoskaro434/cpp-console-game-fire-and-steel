#include "game.h"
#include <time.h> 
#include <stdlib.h>
#include <conio.h>
#include "keyboardControls.h"
#include "statistics.h"
#include"pawn.h"
#include "pathCreator.h"
#include "items.h"

void game::check_collision_for_script_player()
{
	mapElement * tmpForPlayer = aMap.find_element_address(aCharacter.get_obiect_coordinates(), aMap.get_element_head());//Findes map's addres, where player stand.
	mapElement * tmpForScriptPlayer = aMap.find_element_address(aScriptPlayer.get_obiect_coordinates(), aMap.get_element_head());//Findes map's addres, where script player stand.

	if (tmpForPlayer == tmpForScriptPlayer)
	{
		aCharacter.start_battle(aScriptPlayer);

		if (aCharacter.aItems.get_army() > aScriptPlayer.aItems.get_army())//If character won.
		{
			aCharacter.scriptPlayerTurn = false;
			aScriptPlayer.set_obiect_coord(aScriptPlayer.roll_coord());
			aScriptPlayer.delete_path(aScriptPlayer.get_path());
			aScriptPlayer.recover_path();
			aScriptPlayer.aStatistic.increase_survived_days();
			aScriptPlayer.roll_items();
		}
		else aCharacter.set_obiect_coord(aScriptPlayer.roll_coord());
	}
}

void game::check_collision_for_character()
{
	mapElement * tmpForPlayer = aMap.find_element_address(aCharacter.get_obiect_coordinates(), aMap.get_element_head());//Findes map's addres, where player stand.
	mapElement * tmpForScriptPlayer = aMap.find_element_address(aScriptPlayer.get_obiect_coordinates(), aMap.get_element_head());//Findes map's addres, where script player stand.

	if (tmpForPlayer == tmpForScriptPlayer)
	{
		aScriptPlayer.start_battle(aCharacter);

		if (aCharacter.aItems.get_army() > aScriptPlayer.aItems.get_army())//If character won.
		{
			aScriptPlayer.set_obiect_coord(aScriptPlayer.roll_coord());
			aScriptPlayer.delete_path(aScriptPlayer.get_path());
			aScriptPlayer.recover_path();
		}
		else aCharacter.set_obiect_coord(aScriptPlayer.roll_coord());
	}
}

void game::prepare_game()
{
	aMap.load_map();//Loading map.

	aPlacesList.read_map_and_make_list(aMap);//Places creating.

	aScriptPlayer.create_script_player(aMap);

	aCharacter.create_character(aMap,aScriptPlayer.roll_coord());//Using scrip player method to roll coorindates.

}

void game::player_turn()
{
	aGameEvent.do_event(aCharacter, aMap, aKeyboardControls, aPlacesList);

	system("cls");

	check_collision_for_character();

	system("cls");

	show_game();
}

void game::script_player_turn()
{
	aScriptPlayer.do_turn();

	system("cls");

	check_collision_for_script_player();

	system("cls");

	show_game();

	aKeyboardControls.clear_buffor();
}

void game::delete_structures()
{
	/*********************** DELETING MAP ************************/

	aMap.delete_map(aMap.get_element_head());

	/*********************** DELETING PLACES ************************/

	aPlacesList.delete_places(aPlacesList.get_places_head());

	/*** DELETING CREATED PATH FOR SCRIPT PLAYER (IF EXIST) ***/

	aScriptPlayer.delete_path(aScriptPlayer.get_path());
}

bool game::is_binary_exist()
{
	std::ifstream possibleFile;

	possibleFile.open("saved_game.bin", std::ios::binary);

	if (possibleFile)
	{
		possibleFile.close();
		
		return true;
	}
	else
	return false;
}

game::game()
{
	srand(time(NULL));
}

void game::start_game()
{
	/******************************************** LOADING GAME **********************************/

	if(is_binary_exist())//If file is created.
		aLoad.load_game(aCharacter, aScriptPlayer, aMap, aPlacesList);
    else
		prepare_game();//Loading games.



	aKeyboardControls.clear_buffor();

	show_game();

	/******************************************** MAIN GAME LOOP ************************************/

 	while (aKeyboardControls.check_game_loop()==false)
	{

		if (_kbhit() and pawn::scriptPlayerTurn == false)//Player's turn.
			player_turn();

		else if (pawn::scriptPlayerTurn==true) //Script player's turn.
			script_player_turn();
	}

	/********************************************* GAME SAVING *********************************************/

	aSave.save_game(aCharacter, aScriptPlayer, aMap, aPlacesList);


	/**************************************** MEMORY CLEANING ****************************************/

	delete_structures();

}

void game::show_game()
{
	aMap.view_map();

	aCharacter.aStatistic.show_move_ammount_and_survived_days();
}
