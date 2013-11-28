#include "square.h"

// default constructor
Square::Square() : x(1), y(1), m_length(1), m_ch('a') {}

// constructor
Square::Square(int vx, int vy, int length, char ch) : x(vx), y(vy), m_length(length), m_ch(ch) {}
int Square::getLength() const { return m_length; }
int Square::getX() const { return this->x; }
int Square::getY() const { return this->y; }



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

		}
		else
			return;
	}
	if (y < 0) {
		if (cordY + this->m_length >= 0) {
			lengthY = this->m_length + cordY;
			cordY = 0;

		}
		else
			return;
	}
	gotoxy(cordX, cordY);
	for (auto i = 1; i <= lengthY; ++i) {
		for (auto j = 1; j <= lengthX; ++j) {
			if (i == 1) {
				if (x < 0 && y < 0 && j != lengthX)
					cout << " ";
				else if (y < 0) {
					if (j == 1 || j == lengthX)
						cout << ch;
					else
						cout << " ";
				}

				else
					cout << ch;
			}
			else if (i == lengthY)
				cout << ch;
			else {
				if (x < 0 && j != lengthX)
					cout << " ";
				else if (j == 1)
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

		}
		else
			return;
	}
	if (y < 0) {
		if (cordY + this->m_length >= 0) {
			lengthY = this->m_length + cordY;
			cordY = 0;

		}
		else
			return;
	}
	gotoxy(cordX, cordY);
	for (auto i = 1; i <= lengthY; ++i) {
		for (auto j = 1; j <= lengthX; ++j) {
			if (i == 1) {
				if (x < 0 && y < 0 && j != lengthX)
					cout << " ";
				else if (y < 0) {
					if (j == 1 || j == lengthX)
						cout << ch;
					else
						cout << " ";
				}

				else
					cout << ch;
			}
			else if (i == lengthY)
				cout << ch;
			else {
				if (x < 0 && j != lengthX)
					cout << " ";
				else if (j == 1)
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
	int leftX = x;
	int rightX = x + m_length;
	int topY = y;
	int bottomY = y + m_length;

	if (point.getX() <= rightX && point.getX() >= leftX)
	if (point.getY() <= bottomY && point.getY() >= topY)
		return true;
	return false;
}

bool Square::operator==(const Square& rhs) const {
	return (x == rhs.x && y == rhs.y && m_length == rhs.m_length);
}

bool Square::operator<(const Square& rhs) const {
	int s1LeftX = x;
	int s1RightX = x + m_length;
	int s1topY = y;
	int s1bottomY = y + m_length;
	int s1length = m_length;
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
	int s1LeftX = x;
	int s1RightX = x + m_length;
	int s1topY = y;
	int s1bottomY = y + m_length;
	int s1length = m_length;
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
	Point currPoint(x,y);
	for (auto currX = x; currX <= x + m_length; ++currX)
		for (auto currY = y; currY <= y + m_length; ++currY) {
			currPoint.setX(currX);
			currPoint.setY(currY);
			if (rhs.isContainingPoint(currPoint))
				return true;
		}
	return false;
}
