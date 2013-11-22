#include "square_drawing_app.h"
#include "cmd_utils.h"

void SquareDrawingApp::initMenu(Menu& m, vector<string>& options) {
	m.setMenu(options);
}

void SquareDrawingApp::escListener() const {
	while (1) {
		if (_kbhit() && _getch() == 27)
			return;
	}
}

void SquareDrawingApp::run() {
	Square s1, s2;
	Point p1;
	int selection;
	bool flag;

	initMenu(this->mainMenu, this->mainVector);
	initMenu(this->subMenu, this->subVector);

	this->mainMenu.displayOptions();
	this->mainMenu.getSelection();


