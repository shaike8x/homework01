#include "square.h"

// default constructor
Square::Square() : x(1), y(1), m_length(1), m_ch('a') {}

// constructor
Square::Square(int vx, int vy, int length, char ch) : x(vx), y(vy), m_length(length), m_ch(ch) {}
int Square::getLength() const { return m_length; }
int Square::getX() const { return this->x; }
int Square::getY() const { return this->y; }

void Square::draw() const {
	int cordY = this->y, cordX = this->x;
	char ch = this->m_ch;
	int lengthX, lengthY;
	lengthX = lengthY = this->m_length;

	gotoxy(this->x, this->y);

	if (x < 0) {
		if (cordX + this->m_length >= 0) {
			lengthX = this->m_length + cordX;
			cordX = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}
	if (y < 0) {
		if (cordY + this->m_length >= 0) {
			lengthY = this->m_length + cordY;
			cordY = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}

	for (auto i = 0; i <= lengthY; ++i) {
		for (auto j = 0; j <= lengthX; ++j) {
			if (i == 0 || i == lengthY)
				cout << ch;
			else {
				if (j == 0)
					cout << ch;
				else if (j == lengthX)
					cout << ch;
				else
					cout << " ";
			}
		}
		gotoxy(cordX, ++cordY);
	}
}

void Square::draw(const char special) const {
	int cordY = this->y, cordX = this->x;
	char ch = special;
	int lengthX, lengthY;
	lengthX = lengthY = this->m_length;

	gotoxy(this->x, this->y);

	if (x < 0) {
		if (cordX + this->m_length >= 0) {
			lengthX = this->m_length + cordX;
			cordX = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}
	if (y < 0) {
		if (cordY + this->m_length >= 0) {
			lengthY = this->m_length + cordY;
			cordY = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}

	for (auto i = 0; i <= lengthY; ++i) {
		for (auto j = 0; j <= lengthX; ++j) {
			if (i == 0 || i == lengthY)
				cout << ch;
			else {
				if (j == 0)
					cout << ch;
				else if (j == lengthX)
					cout << ch;
				else
					cout << " ";
			}
		}
		gotoxy(cordX, ++cordY);
	}
}

bool Square::isContainingPoint(const Point& point) const {
	int leftX = this->x;
	int rightX = this->x + this->m_length;
	int topY = this->y;
	int bottomY = this->y + this->m_length;

	if (point.getX() <= rightX && point.getX() >= leftX)
	if (point.getY() <= bottomY && point.getY() >= topY)
		return true;
	return false;
}

bool Square::operator==(const Square& rhs) const {
	return (this->x == rhs.x && this->y == rhs.y && this->m_length == rhs.m_length);
}

bool Square::operator<(const Square& rhs) const {
	int s1LeftX = this->x;
	int s1RightX = this->x + this->m_length;
	int s1topY = this->y;
	int s1bottomY = this->y + this->m_length;
	int s1length = this->m_length;
	int s2LeftX = rhs.getX();
	int s2RightX = rhs.getX() + rhs.getLength();
	int s2topY = rhs.getY();
	int s2bottomY = rhs.getY() + rhs.getLength();
	int s2length = rhs.getLength();

	return (
		s1LeftX > s2LeftX &&
		s1RightX < s2RightX &&
		s1topY > s2topY &&
		s1bottomY < s2bottomY &&
		s1length < s2length);
}

bool Square::operator>(const Square& rhs) const {
	int s1LeftX = this->x;
	int s1RightX = this->x + this->m_length;
	int s1topY = this->y;
	int s1bottomY = this->y + this->m_length;
	int s1length = this->m_length;
	int s2LeftX = rhs.getX();
	int s2RightX = rhs.getX() + rhs.getLength();
	int s2topY = rhs.getY();
	int s2bottomY = rhs.getY() + rhs.getLength();
	int s2length = rhs.getLength();

	return (
		s1LeftX < s2LeftX &&
		s1RightX > s2RightX &&
		s1topY < s2topY &&
		s1bottomY > s2bottomY &&
		s1length > s2length);
}

bool Square::overlaps(const Square& rhs) const {
	Point currPoint;
	for (auto currX = this->x; currX <= this->x + this->m_length; ++currX)
		for (auto currY = this->y; currY <= this->y + this->m_length; ++currY) {
			currPoint.setX(currX);
			currPoint.setY(currY);
			if (rhs.isContainingPoint(currPoint))
				return true;
		}
	return false;
}
