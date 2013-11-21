#pragma once
#include "point.h"

bool Point::operator==(const Point& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}


int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;
}

Point::Point(int myX, int myY) : x(myX), y(myY) {}

