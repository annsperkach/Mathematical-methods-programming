using System;

namespace Lab5Proga
{
    class Program
    {
        static void Main(string[] args)
        {
            Romb FigureRomb = new Romb(2,0,2,2,4,2,4,0);
            Console.WriteLine($"Sides: {FigureRomb.Side1()}, {FigureRomb.Side2()}, {FigureRomb.Side3()}, {FigureRomb.Side4()}");
            Console.WriteLine($"Perimeter: {FigureRomb.Perimeter()}");
            Console.WriteLine($"Area: {FigureRomb.Area()}");
            Console.ReadLine();
        }
    }
}