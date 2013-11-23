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
	void setX(const int x);
	void setY(const int y);
	Point(int myX, int myY);
	// comparison operator overload
	bool operator==(const Point& rhs) const;
	void makeMeBlink() const;
};
