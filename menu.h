#pragma once
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Menu
{
private:
	vector<string> options;
	int disabledOption;
	bool someoneDisabled = false;
public:

	Menu();
	void setMenu(vector<string>& vOptions);
	void displayOptions() const;
	void disableOption(int optionNum);
	void disableOption(bool flag);
	int getSelection() const;
};
