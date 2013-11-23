#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Menu
{
private:
	vector<string> options;
	int disabledOption;
	bool someoneDisabled;
public:

	Menu();
	void setMenu(const vector<string> vOptions);
	void displayOptions() const;
	void disableOption(const int optionNum);
	void disableOption(const bool flag);
	int getSelection() const;
};
