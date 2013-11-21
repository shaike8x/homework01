#pragma once
#include <iostream>
#include <list>
#include "point.h"
#include "square.h"

using std::list;
using std::cout;
using std::endl;

class SquareContainer
{
private:
	int totalSquares;
	list<Square> collection;
	list<Square>::iterator iter;
	Point userInputPoint;

public:
	Square& createSquare(); // allocate new square from user input
	void appendSquare(const Square& square); // push a square to the collection
	void deleteSquare(const Square& square); // delete a square from the collection
	void deleteSquare(const Point& point); // same thing, by a given point
};


