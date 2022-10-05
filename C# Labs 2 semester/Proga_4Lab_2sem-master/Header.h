#pragma once
class Trapeze
{
private:
	double x1, x2, x3, x4, y1, y2, y3, y4;

public:
	double Side1, Side2, Side3, Side4, Area, Height, Perimeter;
	Trapeze();
	Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	Trapeze(const Trapeze& copy);
	void AreaCalculation();
	void PerimeterCalculation();

	friend Trapeze operator *(Trapeze TR2, Trapeze TR3);
	friend Trapeze operator -(Trapeze TR3, int value);
};
