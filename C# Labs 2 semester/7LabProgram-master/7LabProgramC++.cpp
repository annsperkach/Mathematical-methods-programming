#include "Header.h"

int main()
{
    double** array = new double* [4];
    array[0] = new double[4]{ 2.4, 5.5, 3.8, -3 };
    array[1] = new double[4]{ 0, 2.1, 8.4, 1.0 };
    array[2] = new double[4]{ -8.6, 0, 5.5, 2 };
    array[3] = new double[4]{ -1, 3, 2, 4 };

    Expression exp1(array[0]);
    Expression exp2(array[1]);
    Expression exp3(array[2]);
    Expression exp4(array[3]);
    Expression* Exp = new Expression[4]{ exp1,exp2,exp3,exp4 };
    double result;
    for (int i = 0; i < 4; i++)
    {
        try
        {
            result = Exp[i].Calculation();
            cout << result << endl;
        }
        catch (const char* error)
        {
            cout << error << endl;
        }
        cout << endl;
    }
}