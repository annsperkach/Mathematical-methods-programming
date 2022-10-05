using System;

namespace Library
{
    class Equation
    {
        private double a, b, c, d;

        public Equation(double a, double b, double c, double d)
        {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
        
        public double Calculation()
        {
            try
            {
                double UpPart = 4 * Math.Log(a / b) + 1;
                double DownPart = c + b - d + a;
                if(DownPart == 0)
                {
                    throw new Exception("Error: The subcortical expression less than 0");
                }
                else if (UpPart == 0 && b == 0)
                {
                    throw new Exception("Error: Division by zero");
                }
                else if (a / b <= 0)
                {
                    throw new Exception("Error: Used number in logarithm <= 0");
                }
                else
                {
                    return UpPart / DownPart;
                }
            }
            catch(Exception error)
            {
                Console.WriteLine(error.Message);
                return 0;
            }
        }
    }
}
