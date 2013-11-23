#include "square_container.h"
#include <iostream>
#include <memory>
using std::unique_ptr;

SquareContainer::SquareContainer() {}

int SquareContainer::getTotalSquares() const { return collection.size(); }

Square& SquareContainer::createSquare() {
	int x, y, length;
	char ch; bool ok = true;
	cout << "Enter x y length ch:\n";
	cin >> x >> y >> length >> ch;
	
	if (length <= 0 || ch == '@')
		ok = false;
	while (!ok) {
		if (length <= 0 || ch == '@') {
			cout << "Can't use this char / Can't use negative length. try again.\n";
			cout << "Enter x y length ch:\n";
			cin >> x >> y >> length >> ch;
		}
		else
			ok = true;
	}
	//unique_ptr<Square> res(new Square(x, y, length, ch));
	Square* res = new Square(x,y,length,ch);
	return *res;
}

void SquareContainer::addSquare() {
	Square& s = createSquare();
	collection.push_back(s);
}

void SquareContainer::deleteSquare(list<Square>::iterator it) {
		collection.erase(it);
	}

void SquareContainer::pushSquareForward(list<Square>::iterator& it) {
	Square& s = *it;
	collection.erase(it);
	collection.push_back(s);
}

Point& SquareContainer::getUserPoint() {
	int x, y;
	cout << "Please enter x y coordinates:\n";
	cin >> x >> y;
	//unique_ptr<Point> res(new Point(x, y));
	Point* p = new Point(x,y);
	return *p;
}

bool SquareContainer::findSquareByPoint(list<Square>::iterator& it, const Point& p) {
	bool res = false;

	for (list<Square>::iterator iter = collection.end(); iter != collection.begin() && res;
		--iter) {
		if (iter->isContainingPoint(p)) {
			res = true;
			it = iter;
			return res;
		}
	}
	return res;
}

void SquareContainer::drawAllSquares() const {
	clrscr();
	if (collection.empty() == false)
		for (auto iter = collection.begin(); iter != collection.end();
			++iter)
			iter->draw();
	else
		cout << "No squares to print.\n";
}

void SquareContainer::drawAllSquares(const Square& selectedSquare) const {
	clrscr();
	if (!collection.empty()) {
		for (auto iter = collection.begin(); iter != collection.end();
			++iter)
			iter->draw();
		selectedSquare.draw('@');
	}
	else
		cout << "No squares to print.\n";
}

void SquareContainer::drawAllSquares(const Point& selectedPoint) const {
	clrscr();
	if (!collection.empty()) {
	for (auto iter = collection.begin(); iter != collection.end();
		++iter)
		iter->draw();
	selectedPoint.makeMeBlink();
	}
	else
		cout << "No squares to print.\n";
}

void SquareContainer::mergeSquares() {
	Point p = getUserPoint();

	bool found2 = findSquareByPoint(selected2, p);

	if (found2 && selected1 != selected2) {
		list<Square>::iterator smallerSquare = (selected1->getLength() <= selected2->getLength() ? selected1 : selected2);
		list<Square>::iterator biggerSquare = (selected1->getLength() <= selected2->getLength() ? selected2 : selected1);
		
		if (*selected1 < *selected2)
			collection.erase(selected1);
		
		else if (*selected1 > *selected2)
			collection.erase(selected2);
		
		else if (selected1->overlaps(*selected2))
			collection.erase(biggerSquare);
		
		else // they must be completly strangers...
			collection.erase(smallerSquare);
	}
	else
		cout << "Square not found! / Square already selected\n";
}

SquareContainer::~SquareContainer() {
	collection.clear();
}

list<Square>::iterator SquareContainer::chooseSquare(bool& flag) {
	cout << "==Choose Square==\n";
	Point p = getUserPoint();
	list<Square>::iterator it;
	flag = findSquareByPoint(it, p);

	if (!flag) {
		cout << "No Match!\n";
		drawAllSquares(p);
	}
	else
		drawAllSquares(*it);
	return it;
}

list<Square>::iterator SquareContainer::getSelcted(int num) const {
	if (num == 1)
		if (ok1)
			return selected1;
	if (num == 2)
		if (ok2)
			return selected2;
}
