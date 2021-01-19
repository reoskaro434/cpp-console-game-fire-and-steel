#ifndef  _DEFINETHINGS_H_
#define _DEFINETHINGS_H_



class defineThings
{
	/******************** ASCII SIGN AND MAP ELEMENTS *********************/

#define ESC 27
#define MOVE_KEY -32
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define E 101
#define I 105
#define SPACE 32
#define markSPACE ' '
#define markM 'M'
#define markZ 'Z'
#define markD 'D'
#define markG 'G'
#define markCHARACTER 'P'
#define markWALL '/'


#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53

//********************* SCRIPT PLAYER *****************

#define SCRIPT_PLAYER_MARK 'B'
#define SCRIPT_PLAYER_roll_item_multiplier 5
//***************** CONST VALUE *******************

#define breakTIMEag 500 
#define timeForRead 2000
#define arcadeGame_roundCost 30
#define arcadeGame_attemptsPerRound 10
#define scriptPLAYER_WAIT 250
#define MOVEAMOUNT 20


//********************* PLAYERS COORDINATES ***************************
#define theX 5
#define theY 5

//SCOUT PARAMETRS 

#define reconGood 0.9
#define reconNormal 0.7
#define reconBad 0.5


//CHARACTER STARTING EQUPIMENT
#define characterMunition 50
#define characterTools 0
#define characterIron 0
#define characterWood 0
#define characterFood 0
#define characterGold 500
#define characterArmy 45

//CASTLE ITEMS
#define castleName "Zamek"
#define castleMunition 100
#define castleTools 20
#define castleIron 80
#define castleWood 50
#define castleFood 100
#define castleGold 1000
#define castleArmy 100
#define castleArmyCost 40
#define castleMunitionCost 30

#define castleMaxTrainingNumber 5
#define castleReward 50
#define castleMinimumLuckNumber 0.6

//WOODCUTTERS ITEMS
#define woodcuttersName "Wioska Drwali"
#define woodcuttersMunition 10
#define woodcuttersTools 20
#define woodcuttersIron 30
#define woodcuttersWood 100
#define woodcuttersFood 40
#define woodcuttersGold 350
#define woodcuttersArmy 40
#define woodcuttersFoodCost 5
#define woodcuttersIronCost 14
#define woodcuttersWoodCost 5

#define woodcuttersRewardPerItem 5
#define woodcuttersMaxIronAmmount 30

//MINERS ITEMS
#define minersName "Wioska Gornikow"
#define minersMunition 10
#define minersTools 30
#define minersIron 100
#define minersWood 30
#define minersFood 25
#define minersGold 400
#define minersArmy 50
#define minersFoodCost 5
#define minersIronCost 8
#define minersWoodCost 10

#define minersRewardPerItem 3
#define minersMaxWoodAmmount 40

//TOWN ITEMS
#define townName "Miasto"
#define townMunition 50
#define townTools 100
#define townIron 200
#define townWood 100
#define townFood 100
#define townGold 2500
#define townArmy 350
#define townFoodCost 10
#define townToolsCost 15

#define townRewardPerItem 6
#define townMaxWoodAmmount 20

};

#endif