#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:
	int totalOptions;
	vector<string> option_strings;
	void displayOptions(bool &flag);

public:

	Menu();
	void set(int option, string option_string);
	int choose(bool &flag);
};
