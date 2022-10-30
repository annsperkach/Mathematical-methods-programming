#include "Header.h"

Expression::Expression(double* array)
{
  a = array[0];
  b = array[1];
  c = array[2];
  d = array[3];
}

double Expression::Calculation()
{
    try
    {
        double UpPart = 4 * log(a / b) + 1;
        double DownPart = c + b - d + a;
        if (DownPart == 0)
        {
            throw ("Error: The subcortical expression less than 0");
        }
        else if (UpPart == 0 && b == 0)
        {
            throw ("Error: Division by zero");
        }
        else if (a / b <= 0)
        {
            throw ("Error: Used number in logarithm <= 0");
        }
        else
        {
            return UpPart / DownPart;
        }
    }
    catch (const char* error)
    {
        cout << error << endl;
        return 0;
    }
}

Expression:: ~Expression()
{
}