#include "square.h"
#include "point.h"
#include <iostream>

using namespace std;

int main(void)
{
	Point myPoint(3, 2);
	Square mySquare(myPoint.getX(), myPoint.getY() , 5, 'a');
	clrscr();
	mySquare.draw();
	gotoxy(-9, -9);
	cout << "T";
	return 0;
}