#include "square_container.h"
#include "menu.h"
#include <vector>
#include <string>

class SquareDrawingApp
{
private:
	vector<string> mainVector;
	vector<string> subVector;
	Menu mainMenu, subMenu;
	
	SquareContainer squares;


	void initMenu(Menu& m, const vector<string> options);
	void escListener() const;

public:
	SquareDrawingApp();
	void run();
};