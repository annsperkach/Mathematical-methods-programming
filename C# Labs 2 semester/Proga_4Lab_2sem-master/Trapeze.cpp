#include "Header.h"
#include <iostream>
#include <math.h>
using namespace std;

Trapeze::Trapeze()
{
}

Trapeze::Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    Side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    Side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    Side3 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    Side4 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
    Height = y2 - y1;
}

Trapeze::Trapeze(const Trapeze& copy)
{
    Side1 = copy.Side1;
    Side2 = copy.Side2;
    Side3 = copy.Side3;
    Side4 = copy.Side4;
    Perimeter = copy.Perimeter;
    Area = copy.Area;
}

void Trapeze::PerimeterCalculation()
{
    Perimeter = Side1 + Side2 + Side3 + Side4;
}

void Trapeze::AreaCalculation()
{
    Area = Height * ((Side1 + Side4) / 2);
}

Trapeze operator *(Trapeze TR2, Trapeze TR3)
{
    Trapeze TR1 = Trapeze();
    TR1.Side1 = TR2.Side1 * TR3.Side1;
    TR1.Side2 = TR2.Side2 * TR3.Side2;
    TR1.Side3 = TR2.Side3 * TR3.Side3;
    TR1.Side4 = TR2.Side4 * TR3.Side4;
    return TR1;
}

Trapeze operator -(Trapeze TR3, int value)
{
    TR3.Side1 -= value;
    TR3.Side2 -= value;
    TR3.Side3 -= value;
    TR3.Side4 -= value;

    return TR3;
}
