#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:
	vector<string> options;
	int disabledOption;
	bool someoneDisabled;
public:

	Menu();
	void setMenu(vector<string>& vOptions);
	void displayOptions() const;
	void disableOption(int optionNum);
	void disableOption(bool flag);
	int getSelection() const;
};
