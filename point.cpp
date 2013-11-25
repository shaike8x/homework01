#pragma once
#include <chrono>
#include <thread>
#include "point.h"
#include "cmd_utils.h"

bool Point::operator==(const Point& rhs) const {
	return (this->x == rhs.x && this->y == rhs.y);
}

int Point::getX() const { return x; }

int Point::getY() const { return y; }

void Point::setX(const int x) { this->x = x; }

void Point::setY(const int y) { this->y = y; }

Point::Point(int myX, int myY) : x(myX), y(myY) {}
Point::Point() : x(1), y(1) {}

void Point::makeMeBlink() const {
	bool flag = false;

	while (!flag && (!_kbhit() || _getch() != 27)) {
		gotoxy(x,y);
		cout << '@';
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		gotoxy(x,y);
		cout << " ";
		std::this_thread::sleep_for(std::chrono::milliseconds(700));

		if (_kbhit())
			flag = (_getch() == 27);
	}
}
