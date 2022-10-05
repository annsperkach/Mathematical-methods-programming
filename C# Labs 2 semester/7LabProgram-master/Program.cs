using System;
using Library;
using System.Collections.Generic;

namespace _7LabProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 4;
            var Equation = new List<Equation>(n) 
            {
                new Equation(0.5, 6, 6, 1),
                new Equation(0, -4, 9, 3),
                new Equation(-8, 0, 5, 2),
                new Equation(-1, 2, 3, 4)
            };

            for (int i = 0; i < n; i++)
            {
                try
                {
                    double Result = Equation[i].Calculation();
                    Console.WriteLine($"{Result}");
                }
                catch (Exception error)
                {
                    Console.WriteLine(error.Message);
                }
                Console.WriteLine();
            }
        }
    }
}
