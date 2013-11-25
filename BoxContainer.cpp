#include "BoxContainer.h"

BoxContainer::BoxContainer(unsigned int max) { maxSquares = max; }
BoxContainer::~BoxContainer() { sqrList.clear(); }
void BoxContainer::reset1() { ok1 = false; }
void BoxContainer::reset2() { ok2 = false; }
int BoxContainer::getTotalSquares() const { return sqrList.size(); }

bool BoxContainer::chooseSquare() {
	s1 = findSquare(ok1);
	if (!ok1) {
		square_found = false;
		return false;
	}
	else {
		square_found = true;
		return true;
	}
}

list<Square>::iterator BoxContainer::findSquare(bool& ok) {
	int x, y;
	list<Square>::iterator res;
	square_found = false;

	clrscr();
	cout << "\t===Choose a Square by Point===\n";
	cout << "\tEnter X Value: ";
	cin >> x;
	cout << endl;
	cout << "\tEnter Y Value: ";
	cin >> y;
	cout << endl;
	p.setX(x);
	p.setY(y);
	for (res = sqrList.begin(); res != sqrList.end(); ++res) {
		if (res->isContainingPoint(p)) {
			ok = true;
			square_found = true;
			return res;
		}
	}
	return res;
}

bool BoxContainer::checkLength(unsigned int length) const {
	return (length > 0);
}

bool BoxContainer::checkChar(char ch) const {
	return (ch != '@');
}

void BoxContainer::drawAllSquares() {
	clrscr();
	for (auto iter = sqrList.begin(); iter != sqrList.end(); ++iter)
		iter->draw(); // draw all the squares

	if (ok1 && square_found) { // if we found a matching square
		s1->draw('@');			// redraw the selected square with @
		p.makeMeBlink();
	}
	if (!square_found)		// if not, make the user point blink
		p.makeMeBlink();
}

void BoxContainer::addSquare() {
	clrscr();
	s = createSquare();
	square_found = true;
	sqrList.push_back(*s);
	delete s;
	drawAllSquares();
}

Square* BoxContainer::createSquare() {
	int x, y;
	unsigned int length;
	char ch;
	bool ok = true;
	cout << "\t===Creating New Square===\n";
	cout << "\tEnter X Value: ";
	cin >> x;
	cout << endl;
	cout << "\tEnter Y Value: ";
	cin >> y;
	cout << endl;
	cout << "\tEnter Square Length: ";
	cin >> length;
	ok = checkLength(length);
	while (!ok) {
		cout << "\tWRONG LENGTH VALUE\n";
		cout << "\tEnter Square Length: \n";
		cin >> length;
		ok = checkLength(length);
	}
	cout << "\tEnter Square Character: ";
	cin >> ch;
	ok = checkChar(ch);
	while (!ok) {
		cout << "\tWRONG CHAR VALUE\n";
		cout << "\tEnter Square Character: ";
		cin >> ch;
		ok = checkChar(ch);
	}

	s = new Square(x, y, length, ch);
	return s;
}

void BoxContainer::deleteSquare() {
	if (!ok1) {
		cout << "\tNo square selected. Cannot complete action.\n";
		return;
	}

	sqrList.erase(s1);
	reset1();
}

void BoxContainer::moveSquareForward() {
	sqrList.splice(sqrList.end(), sqrList, s1);
	reset1();
}

void BoxContainer::mergeSquares() {
	s2 = findSquare(ok2);

	if (!ok2) {
		cout << "\tNo such square.\n";
		return;
	}
	if (s1 == s2) {
		cout << "\tCan't merge with the same square. Nothing to do.\n";
		return;
	}
	if (!ok1) {
		cout << "\tNo first square selected.\n";
		return;
	}
	auto smaller = (s1->getLength() <= s2->getLength()) ? s1 : s2;
	auto bigger = (s1->getLength() < s2->getLength()) ? s2 : s1;

	if (*s1 < *s2)
		sqrList.erase(s1);
	else if (*s1 > *s2)
		sqrList.erase(s2);
	else if (s1->overlaps(*s2))
		sqrList.erase(bigger);
	else // they must be strangers
		sqrList.erase(smaller);

	reset1();
	reset2();
}