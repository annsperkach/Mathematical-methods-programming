#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Romb FigureRomb = Romb(2, 0, 2, 2, 4, 2, 4, 0);
	cout << "Sides:" << endl;
	cout << FigureRomb.Side1() << endl;
	cout << FigureRomb.Side2() << endl;
	cout << FigureRomb.Side3() << endl;
	cout << FigureRomb.Side4() << endl;

	cout << "Perimeter: " << FigureRomb.Perimeter() << endl;
	cout << "Area: " << FigureRomb.Area() << endl;
}
