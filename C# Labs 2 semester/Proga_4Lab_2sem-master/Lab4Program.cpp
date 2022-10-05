#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Trapeze TR1 = Trapeze();
    Trapeze TR2 = Trapeze(10, 20, 40, 50, 10, 40, 40, 10);
    Trapeze TR3 = Trapeze(20, 30, 40, 50, -10, 10, 10, -10);

    cout << "TR2:" << endl;
    TR2.PerimeterCalculation();
    TR2.AreaCalculation();
    cout << "The sides are:" << TR2.Side1 << "," << TR2.Side2 << "," << TR2.Side3 << "," << TR2.Side4 << endl;
    cout << "The perimeter is:" << TR2.Perimeter << endl;
    cout << "The Area is:" << TR2.Area << endl;

    cout << "TR3:" << endl;
    TR3.PerimeterCalculation();
    TR3.AreaCalculation();
    cout << "The sides are:" << TR3.Side1 << "," << TR3.Side2 << "," << TR3.Side3 << "," << TR3.Side4 << endl;
    cout << "The perimeter is:" << TR3.Perimeter << endl;
    cout << "The Area is:" << TR3.Area << endl;

    cout << "TR1:" << endl;
    TR1 = TR2 * TR3;
    cout << "The sides are:" << TR1.Side1 << "," << TR1.Side2 << "," << TR1.Side3 << "," << TR1.Side4 << endl;

    cout << "Subtraction:" << endl;
    TR3 = TR3 - 3;
    cout << "The sides are:" << TR3.Side1 << "," << TR3.Side2 << "," << TR3.Side3 << "," << TR3.Side4 << endl;
}

