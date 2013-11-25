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

public:
	
	// INTERFACE

	// basic getters and constructor
	Square(int vx, int vy, int length, char ch);
	Square();
	int getLength() const;
	int getX() const;
	int getY() const;

	// comparison operators overloaded.
	// square1 < square2 means that square1 is completly inside square2
	bool operator==(const Square& rhs) const;
	bool operator<(const Square& rhs) const;
	bool operator>(const Square& rhs) const;

	// check if the square instrsect other square
	bool overlaps(const Square& rhs) const;

	// draw the square, with default char, and override version
	void draw() const;
	void draw(const char special) const;

	// test if a given point is inside the square
	bool isContainingPoint(const Point& point) const;
};