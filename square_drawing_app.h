#include "square_container.h"
#include "menu.h"

class SquareDrawingApp
{
	Menu main_menu, square_menu;
	SquareContainer square_container;

	void runSquareMenu();
	void initMainMenu();
	void initSquareMenu();
	void esc();

public:
	void run();
};