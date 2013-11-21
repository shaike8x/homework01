#pragma once
#include "square.h"
#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
	static const int ESC_ASCII = 27;
public:
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	// basic constructor
	Point(int myX = 1, int myY = 1);
	// comparison operator overload
	bool operator==(const Point& rhs) const;
	void makeMeBlink() const;
};
