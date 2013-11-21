#include "square.h"

int Square::getLength() const { return m_length; }

Square::Square(int vx, int vy, int length, char ch) : x(vx), y(vy), m_length(length), m_ch(ch) {}

bool Square::operator==(const Square& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y && this->m_length == rhs.m_length);
}

void Square::draw() const
{
	int cordY = this->y, cordX = this->x;
	char ch = this->m_ch;

	gotoxy(this->x, this->y);
	if (x > 0 && y > 0){
		for (auto i = 0; i <= this->m_length; ++i) {
			for (auto j = 0; j <= this->m_length; ++j) {
				if (i == 0 || i == this->m_length)
					cout << ch;
				else {
					if (j == 0)
						cout << ch;
					else if (j == this->m_length)
						cout << ch;
					else
						cout << " ";
				}
			}
			gotoxy(cordX, ++cordY);
		}
	}
	if (x > 0){
		
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