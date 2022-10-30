using System;
using MyLibrary;

namespace Lab4_Programming
{
    class Program
    {
        static void Main(string[] args)
        {
            Trapeze TR1 = new Trapeze();
            Trapeze TR2 = new Trapeze(1, 2, 4, 5, 1, 4, 4, 1);
            Trapeze TR3 = new Trapeze(2, 3, 4, 5, -1, 1, 1, -1);

            Console.WriteLine("\nTR2:");
            TR2.PerimeterCalculation();
            TR2.AreaCalculation();
            Console.WriteLine($"The sides are: {TR2.Side1:f3},{TR2.Side2:f3},{TR2.Side3:f3},{TR2.Side4:f3}");
            Console.WriteLine($"The perimeter is: {TR2.Perimeter:f3}");
            Console.WriteLine($"The Area is: {TR2.Area:f3}");

            Console.WriteLine("\nTR3:");
            TR3.PerimeterCalculation();
            TR3.AreaCalculation();
            Console.WriteLine($"The sides are: {TR3.Side1:f3},{TR3.Side2:f3},{TR3.Side3:f3},{TR3.Side4:f3}");
            Console.WriteLine($"The perimeter is: {TR3.Perimeter:f3}");
            Console.WriteLine($"The Area is: {TR3.Area:f3}");

            Console.WriteLine("\nTR1:");
            TR1 = TR2 * TR3;
            Console.WriteLine($"The sides are: {TR1.Side1:f3},{TR1.Side2:f3},{TR1.Side3:f3},{TR1.Side4:f3}");

            Console.WriteLine("\nSubstraction:");
            TR3 -= 3;
            Console.WriteLine($"The sides are: {TR3.Side1:f3},{TR3.Side2:f3},{TR3.Side3:f3},{TR3.Side4:f3}");
        }

    }
}
