#pragma once
#include <iostream>
#include <list>
#include "point.h"
#include "square.h"

using std::list;
using std::cout;
using std::endl;

class BoxDrawingApp
{
private:
	list<Square> collection;

public:
	Square& createSquare(); // allocate new square from user input
	void appendSquare(const Square& square); // push a square to the collection
	void deleteSquare(const Square& square); // delete a square from the collection
	void deleteSquare(const Point& point); // same thing, by a given point
};
	

