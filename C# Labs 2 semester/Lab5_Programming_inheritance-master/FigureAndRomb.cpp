#include <iostream>
#include <math.h>
using namespace std;
#include "Header.h"
Figure::Figure()
{
}
Figure::Figure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    _x1 = x1;   _y1 = y1;
    _x2 = x2; _y2 = y2;
    _x3 = x3; _y3 = y3;
    _x4 = x4; _y4 = y4;
}

double Figure::Side1()
{
    double FirstSide = sqrt(pow(_x2 - _x1, 2) + pow(_y2 - _y1, 2));
    return FirstSide;
}
double Figure::Side2()
{
    return sqrt(pow(_x3 - _x2, 2) + pow(_y3 - _y2, 2));
}
double Figure::Side3()
{
    return sqrt(pow(_x4 - _x3, 2) + pow(_y4 - _y3, 2));
}
double Figure::Side4()
{
    return sqrt(pow(_x4 - _x1, 2) + pow(_y4 - _y1, 2));
}

Romb::Romb(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    _x1 = x1;   _y1 = y1;
    _x2 = x2; _y2 = y2;
    _x3 = x3; _y3 = y3;
    _x4 = x4; _y4 = y4;
}

double Romb::Area()
{
    double D1 = sqrt(pow(_y3 - _y1, 2) + pow(_x3 - _x1, 2));
    double D2 = sqrt(pow(_y4 - _y2, 2) + pow(_x4 - _x2, 2));
    double AreaCalculation = D1 + D2 / 2;
    return AreaCalculation;
}

double Romb::Perimeter()
{
    double PerimeterCalculation = Side1() + Side2() + Side3() + Side4();
    return PerimeterCalculation;
}
