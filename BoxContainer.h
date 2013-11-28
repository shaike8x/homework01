#pragma once
#include <list>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "square.h"


class BoxContainer {
private:
	
	// DATA MEMBERS
	list<Square>::iterator s1, s2; // iterators for user square selection
	bool ok1, ok2; // indicators if it's ok to use s1, s2
				   // so we dont accidentaly dereference an iterator for
				   // non existing item

	int maxSquares; // maximum squares the instance should handle

	bool square_found; // indicator if a square was found from user point
	Square* s; // used to dynamically allocate new user squares
	Point p; // stores the value of user (x,y) input
	list<Square> sqrList; // doubly linked list to manage the squares

	// IMPLEMENTATION
	list<Square>::iterator findSquare(bool& ok);
	Square* createSquare();
	void reset1();
	void reset2();
	bool checkLength(int length) const;
	bool checkChar(char ch) const;

public:
	
	// constructors
	//BoxContainer(int max); // Maximum squares the instance should handle
	~BoxContainer();		// will clear our list

	// INTERFACE
	int getTotalSquares() const;
	void addSquare(); // add a new square
	void deleteSquare(); // delete a square
	void mergeSquares(); // merge two squares
	void moveSquareForward(); // move a square to the end
	void drawAllSquares() const;	  // draw the squares
	bool chooseSquare();
};

