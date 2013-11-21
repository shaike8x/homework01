#pragma once
#include "point.h"
#include "cmd_utils.h"
class Point;
class Square
{

private:
	int x; 
	int y; 
	int m_length;
	char m_ch;
	int m;

public:
	Square(int vx, int vy, int length, char ch);
	int getLength() const;
	bool operator==(const Square& rhs) const;
	void draw() const;
	bool isContainingPoint(const Point& point) const;
};