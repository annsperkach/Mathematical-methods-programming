using System;

namespace Lab5Proga
{
    class Figure
    {
        protected double[] Coordinate1 = new double[2];
        protected double[] Coordinate2 = new double[2];
        protected double[] Coordinate3 = new double[2];
        protected double[] Coordinate4 = new double[2];

        public Figure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        {
            Coordinate1[0] = x1; Coordinate1[1] = y1;
            Coordinate2[0] = x2; Coordinate2[1] = y2;
            Coordinate3[0] = x3; Coordinate3[1] = y3;
            Coordinate4[0] = x4; Coordinate4[1] = y4;
        }

        public double Side1()
        {
          double FirstSide = Math.Sqrt(Math.Pow(Coordinate2[0] - Coordinate1[0], 2) + Math.Pow(Coordinate2[1] - Coordinate1[1], 2));
            return FirstSide;
        }
        public double Side2()
        {
            return Math.Sqrt(Math.Pow(Coordinate3[0] - Coordinate2[0], 2) + Math.Pow(Coordinate3[1] - Coordinate2[1], 2));
        }
        public double Side3()
        {
            return Math.Sqrt(Math.Pow(Coordinate4[0] - Coordinate3[0], 2) + Math.Pow(Coordinate4[1] - Coordinate3[1], 2));
        }
        public double Side4()
        {
            return Math.Sqrt(Math.Pow(Coordinate4[0] - Coordinate1[0], 2) + Math.Pow(Coordinate4[1] - Coordinate1[1], 2));
        }
    }

    class Romb : Figure
    {
        public Romb(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4) : base(x1, x2, x3, x4, y1, y2, y3, y4)
        {
        }

        public double Area()
        {
            double D1 = Math.Sqrt(Math.Pow(Coordinate3[1] - Coordinate1[1], 2) + Math.Pow(Coordinate3[0] - Coordinate1[0], 2));
            double D2 = Math.Sqrt(Math.Pow(Coordinate4[1] - Coordinate2[1], 2) + Math.Pow(Coordinate4[0] - Coordinate2[0], 2));
            double AreaCalculation = D1 + D2 / 2;
            return AreaCalculation;
        }

        public double Perimeter()
        {
            double PerimeterCalculation = Side1()+Side2()+Side3()+Side4();
            return PerimeterCalculation;
        }
    }

}
