#pragma once
#include "square.h"
#include <iostream>

using namespace std;

class Point {
	
private:
	int x, y;
public:
	int getX() const;
	int getY() const;
	// basic constructor
	Point(int myX, int myY);
	// comparison operator overload
	bool operator==(const Point& rhs) const;
	friend class Square;
};


