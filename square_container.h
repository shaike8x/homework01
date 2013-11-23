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
	list<Square> collection;
	Square& createSquare(); // create square from user input
	bool findSquareByPoint(list<Square>::iterator& it, const Point& point);
	Point& getUserPoint();
	list<Square>::iterator chooseSquare(bool& flag);
	list<Square>::iterator selected1; bool ok1;
	list<Square>::iterator selected2; bool ok2;

public:
	// default constructor
	SquareContainer();
	
	~SquareContainer();
	// return iterator for currently selected square (1 or 2)
	list<Square>::iterator getSelcted(int num) const;
	
	int getTotalSquares() const; // ok
	
	void addSquare(); // ok
	
	void mergeSquares(); // ok
	
	// delete a square from the collection
	void deleteSquare(list<Square>::iterator it); // ok
	
	void pushSquareForward(list<Square>::iterator&);
	// normal draw
	void drawAllSquares() const;
	// print the argument last with @
	void drawAllSquares(const Square& selectedSquare) const;
	// square not found - make point blink
	void drawAllSquares(const Point& selectedPoint) const;
};
