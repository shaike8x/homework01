//#include "square_drawing_app.h"
#include "menu.h"

using namespace std;

int main(void) {
	
	int userInput;
	Menu main_menu;
	main_menu.setOption(1, "Add Square", true);
	main_menu.setOption(2, "Draw Squares", true);
	main_menu.setOption(3, "Choose Square", true);
	main_menu.setOption(8, "Quit", true);
	main_menu.toggleOption(1, false);
	userInput = main_menu.displayAndGetInput();

	cout << "You selected: " << userInput << "." << endl;
}