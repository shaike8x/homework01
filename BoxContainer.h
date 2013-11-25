#pragma once
#include <list>
#include <iostream>
#include "square.h"


class BoxContainer {
private:
	
	// DATA MEMBERS
	list<Square>::iterator s1, s2; // user square selection
	bool ok1, ok2; // indicates if it's ok to use s1, s2
	unsigned int maxSquares;
	bool square_found; // indicator if s square was found from user point
	Square* s;
	Point p;
	list<Square> sqrList;

	// INNER IMPLEMENTATION METHODS
	list<Square>::iterator findSquare(bool& ok);
	Square* createSquare();
	void reset1();
	void reset2();
	bool checkLength(unsigned int length) const;
	bool checkChar(char ch) const;

public:
	
	// INITIALIZATION / DESTRUCTION
	BoxContainer(unsigned int max); // Maximum squares the instance should handle
	~BoxContainer();

	// INTERFACE
	int getTotalSquares() const;
	void addSquare(); // add a new square
	void deleteSquare(); // delete a square
	void mergeSquares(); // merge two squares
	void moveSquareForward(); // move a square to the end
	void drawAllSquares();	  // draw the squares
	bool chooseSquare();
};

