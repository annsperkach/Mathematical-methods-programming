#include <iostream>
#include <cmath>
using namespace std;

class Expression
{
private: double a, b, c, d;
public:
	Expression(double*);
	double Calculation();
	~Expression();
};
