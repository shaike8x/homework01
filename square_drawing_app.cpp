#include "square_drawing_app.h"
#include "cmd_utils.h"


void SquareDrawingApp::initMenu(Menu& m, vector<string>& options) {
	m.setMenu(options);
}

void SquareDrawingApp::escListener() const {
	while (1) {
		if (_kbhit() && _getch() == 27) {
			clrscr();
			return;
		}
	}
}

void SquareDrawingApp::run() {
	Square s1, s2;
	Point p1, p2;
	SquareContainer sqrs = this->squares;
	int selection, selection2;
	bool foundFlag1, foundFlag2;

	initMenu(this->mainMenu, this->mainVector);
	initMenu(this->subMenu, this->subVector);

	this->mainMenu.displayOptions();
	selection = this->mainMenu.getSelection();
	while (selection != 8)
	{
		this->mainMenu.displayOptions();
		selection = this->mainMenu.getSelection();

		switch (selection) {
		case 1: // add square
			s1 = this->squares.createSquare();
			this->squares.appendSquareToList(s1);
			this->squares.drawAllSquares();
			escListener();
			break;
		case 2: // draw squares
			this->squares.drawAllSquares();
			escListener();
			break;
		case 3: // choose square
			p1 = this->squares.getUserPoint();
			foundFlag1 = this->squares.findSquareByPoint(p1, s1);
			foundFlag1 ? this->squares.drawAllSquares(s1) : this->squares.drawAllSquares(p1);
			if (foundFlag1) {
				do { 
					this->subMenu.displayOptions();
					selection2 = this->subMenu.getSelection();

					switch (selection2) {
				case 1: // go back to main
					this->squares.drawAllSquares();
					escListener();
					break;
				case 2: // delete the square
					this->squares.deleteSquare(s1);
					escListener();
					break;
				case 3: // move forward
					this->squares.pushSquareForward(s1);
					this->squares.drawAllSquares();
					escListener();
					break;
				case 4: // merge with other square
					p2 = this->squares.getUserPoint();
					foundFlag2 = this->squares.findSquareByPoint(p2, s2);
					if (foundFlag2)
						this->squares.mergeSquares(s1, s2);
					else {
						cout << "No such square\n";
						std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					}
					this->squares.drawAllSquares();
					escListener();
					break;
				}
				} while (selection2 != 1);
			}
			break;
		
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
