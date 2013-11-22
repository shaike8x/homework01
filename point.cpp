#pragma once
#include <chrono>
#include <thread>
#include "point.h"
#include "cmd_utils.h"

bool Point::operator==(const Point& rhs) const {
	return (this->x == rhs.x && this->y == rhs.y);
}

int Point::getX() const { return this->x; }

int Point::getY() const { return this->y; }

void Point::setX(int x) { this->x = x; }

void Point::setY(int y) { this->y = y; }

Point::Point(int myX, int myY) : x(myX), y(myY) {}

void Point::makeMeBlink() const {
	while (1) {
		if (_kbhit() || _getch() == ESC_ASCII)
			break;
		gotoxy(this->x, this->y);
		cout << '@';
		// Couldn't find sleep() on my system so this is what I got from google...
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		gotoxy(this->x, this->y);
		cout << ' ';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}