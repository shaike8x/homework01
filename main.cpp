#include "square.h"
#include "point.h"
#include <iostream>

using namespace std;

int main(void)
{
	// added comment
	Point myPoint(-3, 2);
	Square mySquare(myPoint.getX(), myPoint.getY() , 8, 'a');
	clrscr();
	mySquare.draw();
	
	
	return 0;
}