#include "menu.h"
#include "cmd_utils.h"


Menu::Menu() {
	someoneDisabled = false;
	disabledOption = 9;
}

void Menu::displayOptions() const {
	clrscr();
	for (unsigned int i = 0; i <= options.size(); ++i) {
		if (someoneDisabled && i != disabledOption)
			std::cout << i + 1 << ".\t" << options[i] << endl;
	}
}

void Menu::setMenu(const vector<string> vOptions) {
	options.reserve(vOptions.size());
	options = vOptions;
}

void Menu::disableOption(int optionNum) {
	disabledOption = optionNum;
	someoneDisabled = true;
}

void Menu::disableOption(bool flag) {
	someoneDisabled = false;
}

int Menu::getSelection() const {
	std::cout << "Waiting for selection: ";
	unsigned int res;
	cin >> res;
	
	while (res <= 0 || res > options.size() || (res == disabledOption && 
		someoneDisabled)) {
		std::cout << endl;
		std::cout << "Wrong option. Please try again.\n";
		std::cout << "Waiting for selection: ";
		cin >> res;
	}
	return res;
}



	
