#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Figure
{
protected:
    double _x1;
    double _y1;
    double _x2;
    double _y2;
    double _x3;
    double _y3;
    double _x4;
    double _y4;

public:
    Figure();
    Figure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    double Side1();
    double Side2();
    double Side3();
    double Side4();
};

class Romb : public Figure
{
public:
    Romb(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    double Area();
    double Perimeter();
};

