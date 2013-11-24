#include "BoxContainer.h"
#include "menu.h"
#include <vector>
#include <string>
#include <iostream>

class SquareDrawingApp
{
private:
	int userSelection;
	int userSubSelection;
	bool found = false;
	Menu mainMenu, subMenu;
	
	BoxContainer squares;

public:
	SquareDrawingApp(int max);
	void escListen();
	void run();
	void setupMainMenu();
	void setupSubMenu();
	void runSubMenu();
};