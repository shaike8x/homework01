#include "square_container.h"
#include "menu.h"
#include <vector>
#include <string>

class SquareDrawingApp
{
private:
	
	vector<string> mainVector = { "Add Square", "Draw Squares",
		"Choose a Square", "Quit"};
	vector<string> subVector = { "Cancel Selection", "Delete Square",
		"Move Square to Front", "Merge with other Square"};
	Menu mainMenu, subMenu;
	
	SquareContainer squares;


	void initMenu(Menu& m, vector<string>& options);
	void escListener() const;

public:
	void run();
};