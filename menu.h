#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// a basic data structure to store the options text and number
// with the ability to enable/disable each option.
typedef struct option {
	bool active;
	string text;
	unsigned int id;
} Option;

class Menu
{
private:
	// DATA MEMBERS
	vector<Option> options;

	// IMPLEMENTATION

	// check if the selected option is valid and enabled
	bool checkOption(int choice);
public:
	// INTERFACE
		// add an option to the menu
		void setOption(unsigned int id, string text, bool active);

		// toggle between active/disabled option
		void toggleOption(unsigned int id, bool flag);

		// display the menu and get user input
		int displayAndGetInput();
};
