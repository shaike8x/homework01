#include "square_drawing_app.h"
#include "cmd_utils.h"

void SquareDrawingApp::setupMainMenu() {
	mainMenu.setOption(1, "Add Square", true);
	mainMenu.setOption(2, "Draw Squares", true);
	mainMenu.setOption(3, "Choose Square", true);
	mainMenu.setOption(8, "Quit", true);
}

void SquareDrawingApp::setupSubMenu() {
	subMenu.setOption(1, "Cancel Selection (Go Back)", true);
	subMenu.setOption(2, "Delete Selected Square", true);
	subMenu.setOption(3, "Push Selected Square to Front", true);
	subMenu.setOption(4, "Merge with another Square", true);
}

void SquareDrawingApp::runSubMenu() {
	clrscr();
	userSubSelection = subMenu.displayAndGetInput();

	switch (userSubSelection) {
	case 1:
		userSelection = mainMenu.displayAndGetInput();
		break;
	case 2:
		squares.deleteSquare();
		squares.drawAllSquares();
		escListen();
		break;
	case 3:
		squares.moveSquareForward();
		squares.drawAllSquares();
		escListen();
		break;
	case 4:
		squares.mergeSquares();
		squares.drawAllSquares();
		escListen();
		break;
	}
}

void SquareDrawingApp::run() {
	
	setupMainMenu();
	setupSubMenu();

	userSelection = mainMenu.displayAndGetInput();

	while (userSelection != 8) {

		if (squares.getTotalSquares() >= 10)
			mainMenu.toggleOption(1, false);
		else
			mainMenu.toggleOption(1, true);

		switch (userSelection) {
		case 1: // add square
			squares.addSquare();
			squares.drawAllSquares();
			escListen();
			break;
		case 2: // draw squares
			squares.drawAllSquares();
			escListen();
			break;
		case 3: // choose square
			found = squares.chooseSquare();
			squares.drawAllSquares();
			escListen();
			if (found)
				runSubMenu();
			break;
		}
		userSelection = mainMenu.displayAndGetInput();
	}
}

SquareDrawingApp::SquareDrawingApp(int max) : squares(max) {}

void SquareDrawingApp::escListen() {
	int ch;
	ch = _getch();

	while (ch != 27) {
		ch = _getch();
	}
	clrscr();
}
