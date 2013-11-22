#pragma once
#include "point.h"
#include "cmd_utils.h"
class Point;
class Square {
private:
	int x;
	int y;
	int m_length;
	char m_ch;
	int m;

public:
	Square(int vx, int vy, int length, char ch);
	Square();
	int getLength() const;
	int getX() const;
	int getY() const;
	bool operator==(const Square& rhs) const;
	// s1 < s2: means that s1 is completly inside s2
	bool operator<(const Square& rhs) const;
	bool operator>(const Square& rhs) const;
	bool overlaps(const Square& rhs) const;
	void draw() const;
	void draw(const char special) const;
	bool isContainingPoint(const Point& point) const;
};

// TODO: overload <,>,!= for merging
// implement the acual merge in square_container
// create menu