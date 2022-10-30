using System;

namespace MyLibrary
{
    class Trapeze
    {
        private double x1, x2, x3, x4, y1, y2, y3, y4;
        public double Side1 { get; private set; }
        public double Side2 { get; private set; }
        public double Side3 { get; private set; }
        public double Side4 { get; private set; }

        public double Height { get; private set; }
        public double Area { get; private set; }
        public double Perimeter { get; private set; }

        public Trapeze()
        {
        }

        public Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        {
            Side1 = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
            Side2 = Math.Sqrt(Math.Pow(x3 - x2, 2) + Math.Pow(y3 - y2, 2));
            Side3 = Math.Sqrt(Math.Pow(x4 - x3, 2) + Math.Pow(y4 - y3, 2));
            Side4 = Math.Sqrt(Math.Pow(x4 - x1, 2) + Math.Pow(y4 - y1, 2));
            Height = y2 - y1;
        }

        public Trapeze(Trapeze copy)
        {
            Side1 = copy.Side1;
            Side2 = copy.Side2;
            Side3 = copy.Side3;
            Side4 = copy.Side4;
            Perimeter = copy.Perimeter;
            Area = copy.Area;
        }

        public void PerimeterCalculation()
        {
            Perimeter = Side1 + Side2 + Side3 + Side4;
        }

        public void AreaCalculation()
        {
            Area = Height * ((Side1 + Side4) / 2);
        }

        public static Trapeze operator *(Trapeze TR2, Trapeze TR3)
        {
            Trapeze TR1 = new Trapeze();
            TR1.Side1 = TR2.Side1 * TR3.Side1;
            TR1.Side2 = TR2.Side2 * TR3.Side2;
            TR1.Side3 = TR2.Side3 * TR3.Side3;
            TR1.Side4 = TR2.Side4 * TR3.Side4;
            return TR1;
        }

        public static Trapeze operator -(Trapeze TR3, int value)
            {
            TR3.Side1 -= value;
            TR3.Side2 -= value;
            TR3.Side3 -= value;
            TR3.Side4 -= value;

            return TR3;
            }

    }
}
