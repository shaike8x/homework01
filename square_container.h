#pragma once
#include <iostream>
#include <list>
#include "point.h"
#include "square.h"

using std::list;
using std::cout;
using std::endl;

class SquareContainer {
private:
	int totalSquares;
	list<Square> collection;
	list<Square>::iterator iter = collection.end();
	Point userInputPoint;

public:
	SquareContainer();
	int getTotalSquares() const;
	Square& createSquare(); // create square from user input
	bool findSquareByPoint(const Point& point, Square& square);
	Point& getUserPoint();
	void appendSquareToList(const Square& square);
	void deleteSquare(const Square& square); // delete a square from the collection
	// void deleteSquare(const Point& point); // same thing, by a given point
	void pushSquareForward(const Square& square);
	void drawAllSquares() const; // normal draw
	void drawAllSquares(const Square& selectedSquare) const; // print the argument last with @
	void drawAllSquares(const Point& selectedPoint) const; // square not found - make point blink
};
