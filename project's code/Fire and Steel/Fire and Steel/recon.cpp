#include <iostream>
#include "recon.h"
#include "defineThings.h"
#include "places.h"

void recon::show_for_good(items aItems)
{
	std::cout << "O to co udalo Ci sie dowiedziec." << std::endl;
	std::cout <<std::endl;
	aItems.show_all_obiect_items_and_army();
}

void recon::show_for_normal(items aItems)
{
	std::cout << "O to co udalo Ci sie dowiedziec." << std::endl;
	std::cout << std::endl;
	aItems.show_all_obiect_items();
	std::cout << std::endl;
}

void recon::show_for_bad(items aItems)
{
	std::cout << "O to co udalo Ci sie dowiedziec." << std::endl;
	std::cout << std::endl;
	std::cout<<"Zywnosc " <<aItems.get_food()<<std::endl;
	std::cout << "Drewno " << aItems.get_wood() << std::endl;
	std::cout << "Zelazo " << aItems.get_iron() << std::endl;
	std::cout << std::endl;
}

void recon::do_recon(items &aItemsFromPlace, character &aCharacter)
{
	system("CLS");

	float luck;

	aArcadeGame.do_arcade_game(breakTIMEag, aCharacter.aItems.get_food());

	luck = aArcadeGame.get_last_rolled_luck();

	if (luck >= reconGood) show_for_good(aItemsFromPlace);
	
	else if (luck >= reconNormal and luck < reconGood) show_for_normal(aItemsFromPlace);
	
	else if (luck >= reconBad and luck < reconNormal) show_for_bad(aItemsFromPlace);
	
	else std::cout << "Nic nie udalo Ci sie dowiedziec." << std::endl;
		
	std::cout << std::endl;
	system("pause");
}
