#pragma once
#include "square.h"
#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:

	// INTERFACE

	// basic getters / setters
	int getX() const;
	int getY() const;
	void setX(const int x);
	void setY(const int y);
	Point(int myX, int myY);
	Point();

	// comparison operator overload so we can compare points.
	bool operator==(const Point& rhs) const;

	// make the point blink
	void makeMeBlink() const;
};
