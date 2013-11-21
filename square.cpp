#include "square.h"

int Square::getLength() const { return m_length; }
// constructor
Square::Square(int vx, int vy, int length, char ch) : x(vx), y(vy), m_length(length), m_ch(ch) {}
// default constructor
Square::Square() : x(1), y(1), m_length(1), m_ch('a') {}

bool Square::operator==(const Square& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y && this->m_length == rhs.m_length);
}

void Square::draw() const
{
	int cordY = this->y, cordX = this->x;
	char ch = this->m_ch;
	int lengthX, lengthY;
	lengthX = lengthY = this->m_length;

	gotoxy(this->x, this->y);

	if (x < 0){
		if (cordX + this->m_length >= 0){
			lengthX = this->m_length + cordX;
			cordX = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}
	if (y < 0){
		if (cordY + this->m_length >= 0){
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

	if (x < 0){
		if (cordX + this->m_length >= 0){
			lengthX = this->m_length + cordX;
			cordX = 0;
			gotoxy(cordX, cordY);
		}
		else
			return;
	}
	if (y < 0){
		if (cordY + this->m_length >= 0){
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

bool Square::isContainingPoint(const Point& point) const
{
	int leftX = this->x;
	int rightX = this->x + this->m_length;
	int topY = this->y;
	int bottomY = this->y + this->m_length;

	if (point.getX() <= rightX && point.getX() >= leftX)
	if (point.getY() <= bottomY && point.getY() >= topY)
		return true;
	return false;
}