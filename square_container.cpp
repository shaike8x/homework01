#include "square_container.h"
#include <iostream>
#include <memory>
using std::unique_ptr;

SquareContainer::SquareContainer() { this->totalSquares = 0; }

int SquareContainer::getTotalSquares() const { return this->totalSquares; }

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

void SquareContainer::appendSquareToList(const Square& square) {
	this->collection.push_back(square);
	(this->totalSquares)++;
}

void SquareContainer::deleteSquare(const Square& square) {
	this->collection.remove(square);
	(this->totalSquares)--;
}

void SquareContainer::pushSquareForward(const Square& square) {
	list<Square>::iterator temp;
	for (temp = this->collection.begin(); temp != this->collection.end(); ++temp)
	if (*temp == square)
		this->collection.erase(temp);
	this->collection.push_back(square);
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

	for (list<Square>::reverse_iterator riter = this->collection.rbegin(); riter != this->collection.rend();
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
	for (auto iter = this->collection.begin(); iter != this->collection.end();
		++iter)
		iter->draw();
}

void SquareContainer::drawAllSquares(const Square& selectedSquare) const {
	clrscr();
	for (auto iter = this->collection.begin(); iter != this->collection.end();
		++iter)
		iter->draw();
	selectedSquare.draw('@');
}

void SquareContainer::drawAllSquares(const Point& selectedPoint) const {
	clrscr();
	for (auto iter = this->collection.begin(); iter != this->collection.end();
		++iter)
		iter->draw();
	selectedPoint.makeMeBlink();
}