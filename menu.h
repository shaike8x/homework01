#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct option {
	bool active;
	string text;
	unsigned int id;
} Option;

class Menu
{
private:
	vector<Option> options;
	bool checkOption(int choice);
public:
		void setOption(unsigned int id, string text, bool active);
		void toggleOption(unsigned int id, bool flag);
		int displayAndGetInput();
};
