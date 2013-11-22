#include "square_drawing_app.h"
#include "cmd_utils.h"


void SquareDrawingApp::initMenu(Menu& m, vector<string>& options) {
	m.setMenu(options);
}

void SquareDrawingApp::escListener() const {
	int ch = _getch();
	while (ch != 27)
		ch = _getch();
	clrscr();
}

void SquareDrawingApp::run() {
	Square s1, s2;
	Point p1, p2;
	int selection = 1, selection2;
	bool foundFlag1, foundFlag2;

	initMenu(mainMenu, mainVector);
	initMenu(subMenu, subVector);

	while (selection != 8) {
		if (squares.getTotalSquares() >= 10)
			mainMenu.disableOption(1);
		else
			mainMenu.disableOption(false);
		mainMenu.displayOptions();
		selection = mainMenu.getSelection();

		switch (selection) {
		case 1: // add square
			s1 = squares.createSquare();
			squares.appendSquareToList(s1);
			squares.drawAllSquares();
			escListener();
			break;
		case 2: // draw squares
			squares.drawAllSquares();
			escListener();
			break;
		case 3: // choose square
			p1 = squares.getUserPoint();
			foundFlag1 = squares.findSquareByPoint(p1, s1);
			foundFlag1 ? squares.drawAllSquares(s1) : squares.drawAllSquares(p1);
			if (foundFlag1) {
				subMenu.displayOptions();
				selection2 = subMenu.getSelection();
				switch (selection2) {
				case 1: // go back to main
					squares.drawAllSquares();
					escListener();
					break;
				case 2: // delete the square
					squares.deleteSquare(s1);
					escListener();
					break;
				case 3: // move forward
					squares.pushSquareForward(s1);
					squares.drawAllSquares();
					escListener();
					break;
				case 4: // merge with other square
					p2 = squares.getUserPoint();
					foundFlag2 = this->squares.findSquareByPoint(p2, s2);
					if (foundFlag2)
						squares.mergeSquares(s1, s2);
					else {
						cout << "No such square\n";
						std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					}
					squares.drawAllSquares();
					escListener();
					break;
				}
			break; // case 3
			}
			else {
				cout << "Square not found.\n";
				break;
			}
		case 8:
			cout << "Bye bye!\n";
			break;
		}
	}
}

SquareDrawingApp::SquareDrawingApp() {
	mainVector.push_back("Add Square");
	mainVector.push_back("Draw Squares");
	mainVector.push_back("Choose a Square");
	mainVector.push_back("Quit");

	subVector.push_back("Go Back to Main");
	subVector.push_back("Delete Square");
	subVector.push_back("Move Square to Front");
	subVector.push_back("Merge with other Square");
}
