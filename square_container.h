#pragma once
#include <iostream>
#include <list>
#include "point.h"
#include "square.h"
#include <chrono>
#include <thread>

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
	// default constructor
	SquareContainer();
	~SquareContainer();
	int getTotalSquares() const;
	// create square from user input
	Square& createSquare();
	bool findSquareByPoint(const Point& point, Square& square);
	Point& getUserPoint();
	void appendSquareToList(const Square& square);
	void mergeSquares(const Square& s1, const Square& s2);
	// delete a square from the collection
	void deleteSquare(const Square& square);
	void pushSquareForward(const Square& square);
	// normal draw
	void drawAllSquares() const;
	// print the argument last with @
	void drawAllSquares(const Square& selectedSquare) const;
	// square not found - make point blink
	void drawAllSquares(const Point& selectedPoint) const;
};
