#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "arcadeGame.h"
#include "defineThings.h"


arcadeGame::arcadeGame()
{
	numbOfAttemptsPerRound = arcadeGame_attemptsPerRound;
	oneRoundCost = arcadeGame_roundCost;
}

int arcadeGame::get_round_cost()
{
	return oneRoundCost;
}

void arcadeGame::automatic_luck()
{
	int numb = (rand() % 101);
	lastRolledLuck = numb;
	lastRolledLuck *= 0.01;

}

float arcadeGame::get_last_rolled_luck()
{
	return lastRolledLuck;
}

bool arcadeGame::pay_for_next_round(int &foodNumber)
{
	if (foodNumber >= oneRoundCost) //Return's true if player have enough food.
	{
		system("cls");
		foodNumber -= oneRoundCost;
		std::cout << "Kolejne losowanie szczescia kosztuje Cie " << oneRoundCost <<" sztuk zywnosci."<< std::endl;
		Sleep(timeForRead);
		do_arcade_game(breakTimeForNow, foodNumber);//
		return true;
	}
	else
	{
		system("cls");
		
		std::cout << "Niestety nie masz juz sil na kolejne losowanie."<<std::endl;
		std::cout << "Twoja szczescie zostanie wylosowane przez komputer";
		
		automatic_luck();
		Sleep(timeForRead);
		
		system("cls");
		return false;
	}
}

void arcadeGame::do_arcade_game(const int breakTime, int &foodNumber)
{
	breakTimeForNow = breakTime;

	system("cls");
	std::cout << "Traf najwieksza liczbe. Masz " << numbOfAttemptsPerRound << " szans." << std::endl;
	
	Sleep(timeForRead);
	
	system("cls");
	
	arcadeKeyboardControls.clear_buffor();
	int tmp = numbOfAttemptsPerRound;
	int attempt = 1;
	do
	{
		
			numb = ((rand() % 100)+1);
			std::cout << attempt << "   " << numb << std::endl;
			Sleep(breakTime);
			if (_kbhit())
			{
				arcadeKeyboardControls.set_pressed_key();
			}
			tmp--;
			attempt++;

	} while (arcadeKeyboardControls.get_enum_key() != keyboardControls::keySpace and tmp != 0);

	if (arcadeKeyboardControls.get_enum_key() == keyboardControls::keySpace)
	{

		arcadeKeyboardControls.clear_buffor();

		std::cout << "Trafiona liczba: " << numb << std::endl;
		system("pause");
		lastRolledLuck = numb;
		lastRolledLuck *= 0.01;
		system("cls");
	}
	else
	{
			pay_for_next_round(foodNumber);
	}
	arcadeKeyboardControls.clear_buffor();
}
