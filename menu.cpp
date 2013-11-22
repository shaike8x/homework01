#include "menu.h"
#include "cmd_utils.h"


Menu::Menu() {
	this->someoneDisabled = false;
	this->disabledOption = 9;
}

void Menu::displayOptions() const {
	clrscr();
	for (auto i = 1; i <= this->options.size(); ++i) {
		if (someoneDisabled && i != disabledOption)
			std::cout << i << ".\t" << options[i] << endl;
	}
}

void Menu::setMenu(vector<string>& vOptions) {
	this->options = vOptions;
}

void Menu::disableOption(int optionNum) {
	this->disabledOption = optionNum;
	this->someoneDisabled = true;
}

void Menu::disableOption(bool flag) {
	this->someoneDisabled = false;
}

int Menu::getSelection() const {
	std::cout << "Waiting for selection: ";
	int res;
	cin >> res;
	
	while (res <= 0 || res > this->options.size() || (res == this->disabledOption && 
		this->someoneDisabled)) {
		std::cout << endl;
		std::cout << "Wrong option. Please try again.\n";
		std::cout << "Waiting for selection: ";
		cin >> res;
	}
	return res;
}



	
