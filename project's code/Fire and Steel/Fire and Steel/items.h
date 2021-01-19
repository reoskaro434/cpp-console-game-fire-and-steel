#ifndef  _ITEMS_H_
#define  _ITEMS_H_

class items
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	int army;//Stores army.
	int gold;//Stores gold.
	int food;//Stores food.
	int wood;//Sotres wood.
	int iron;//Stores iron.
	int tools;//Stores tools.
	int munition;//Stores munition.

	int armyCost;//Stores army's cost.
	int foodCost;//Stores food's cost.
	int woodCost;//Stores wood's cost.
	int ironCost;//Stores iron's cost.
	int toolsCost;//Stores tools's cost.
	int munitionCost;//Stores munition's cost.


public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets all atributes to 0.
	items();

	//Adds from aItems all items, and delete items from aItems.
	items & operator+=(items &aItems);

	//Shows all items, wtihout army.
	void show_all_obiect_items();

	//Shows wood and food.
	void show_wood_and_food();
	
	//Shows iron and food.
	void show_iron_and_food();

	//Shows tools and food.
	void show_tools_and_food();

	//Shows munitions and real army (not fighting soldiers).
	void show_munition_and_inf_army();

	//Shows all items and army.
	void show_all_obiect_items_and_army();


	//Sets new ammount of army.Variable value is a new value.
	void set_army(int value);

	//Sets new ammount of gold.Variable value is a new value.
	void set_gold(int value);

	//Sets new ammount of food.Variable value is a new value.
	void set_food(int value);

	//Sets new ammount of wood.Variable value is a new value.
	void set_wood(int value);

	//Sets new ammount of iron.Variable value is a new value.
	void set_iron(int value);
	
	//Sets new ammount of tools.Variable value is a new value.
	void set_tools(int value);

	//Sets new ammount of munition.Variable value is a new value.
	void set_munition(int value);

	//Returns army.
	int & get_army();

	//Returns gold.
	int & get_gold();

	//Returns food.
	int & get_food();

	//Returns wood.
	int & get_wood();

	//Returns iron.
	int & get_iron();

	//Returns tools.
	int & get_tools();

	//Returns munition.
	int & get_munition();

	//Returns army's cost.
	int get_armyCost();

	//Returns food's cost.
	int get_foodCost();

	//Returns wood's cost.
	int get_woodCost();

	//Returns iron's cost.
	int get_ironCost();

	//Returns tools cost.
	int get_toolsCost();

	//Returns munition's cost.
	int get_munitionCost();
		
	//Sets new army's cost value.Variable value is a new value.
	void  set_armyCost(int value);

	//Sets new food's cost value.Variable value is a new value.
	void  set_foodCost(int value);

	//Sets new wood's cost value.Variable value is a new value.
	void  set_woodCost(int value);

	//Sets new iron's cost value.Variable value is a new value.
	void  set_ironCost(int value);

	//Sets new tools cost value.Variable value is a new value.
	void  set_toolsCost(int value);

	//Sets new munition's cost value.Variable value is a new value.
	void  set_munitionCost(int value);
};


#endif