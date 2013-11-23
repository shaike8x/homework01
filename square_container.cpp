#include "square_container.h"
#include <iostream>
#include <memory>
using std::unique_ptr;

SquareContainer::SquareContainer() { totalSquares = 0; }

int SquareContainer::getTotalSquares() const { return totalSquares; }

Square& SquareContainer::createSquare() {
	int x, y, length;
	char ch;
	cout << "Enter x y length ch:\n";
	cin >> x >> y >> length >> ch;

	while (ch == '@' || length <= 0) {
		cout << "Can't use this char / Can't use negative length. try again.\n";
		cout << "Enter x y length ch:\n";
		cin >> x >> y >> length >> ch;
	}
	unique_ptr<Square> res(new Square(x, y, length, ch));
	return *res;
}

void SquareContainer::addSquare(const Square& square) {
	collection.push_back(square);
	totalSquares++;
}

void SquareContainer::deleteSquare(const Square& square) {
	collection.remove(square);
	(totalSquares)--;
}

void SquareContainer::pushSquareForward(const Square& square) {
	list<Square>::iterator temp;
	for (temp = collection.begin(); temp != collection.end(); ++temp)
	if (*temp == square)
		collection.erase(temp);
	collection.push_back(square);
}

Point& SquareContainer::getUserPoint() {
	int x, y;
	cout << "Please enter x y coordinates:\n";
	cin >> x >> y;
	unique_ptr<Point> res(new Point(x, y));
	return *res;
}

bool SquareContainer::findSquareByPoint(const Point& point, Square& square) {
	bool res = false;

	for (list<Square>::reverse_iterator riter = collection.rbegin(); riter != collection.rend();
		++riter) {
		if (riter->isContainingPoint(point)) {
			res = true;
			square = *riter;
			return res;
		}
	}
	return res;
}

void SquareContainer::drawAllSquares() const {
	clrscr();
	for (auto iter = collection.begin(); iter != collection.end();
		++iter)
		iter->draw();
}

void SquareContainer::drawAllSquares(const Square& selectedSquare) const {
	clrscr();
	for (auto iter = collection.begin(); iter != collection.end();
		++iter)
		iter->draw();
	selectedSquare.draw('@');
}

void SquareContainer::drawAllSquares(const Point& selectedPoint) const {
	clrscr();
	for (auto iter = collection.begin(); iter != collection.end();
		++iter)
		iter->draw();
	selectedPoint.makeMeBlink();
}

void SquareContainer::mergeSquares(const Square& s1, const Square& s2) {
	Square smallerSquare = (s1.getLength() <= s2.getLength() ? s1 : s2);
	Square biggerSquare = (s1.getLength() <= s2.getLength() ? s2 : s1);
	if (s1 < s2)
		deleteSquare(s1);
	else if (s1 > s2)
		deleteSquare(s2);
	else if (s1.overlaps(s2))
		deleteSquare(biggerSquare);
	else // they must be completly strangers...
		deleteSquare(smallerSquare);
}

SquareContainer::~SquareContainer() {
	collection.clear();
}
