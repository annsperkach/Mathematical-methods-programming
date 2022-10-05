using System;

namespace SRM06Lab
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ForegroundColor = ConsoleColor.Black; //налаштування кольору консолі
            Console.BackgroundColor = ConsoleColor.Yellow;

            double e = 0.00001;   //задана точність
            Console.WriteLine("Our polynomial:\nx^5+3*x^2-2^x-1=0\nAccuracy:{0}", e);  //Знайдений поліном під час допрограмного етапу
            double[] interval1 = { -2, -1, 0.366 };    //Наші знайдені проміжки за допомогою ряду Штурмана
            double[] interval2 = { -1, -0.25, 1 };

            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("___________________________________________________");
                Console.WriteLine("x{0} Є [{1};{2}]", i + 1, interval1[i], interval2[i]);
                MethodBisection(interval1[i], interval2[i], e);  //визиваємо наші методи
                MethodHord(interval1[i], interval2[i], e);
                MethodNewton(interval1[i], interval2[i], e);
                Console.WriteLine();
            }
        }

        static double Func(double x)
        {
            int n = 5;
            int[] A = { -1, -2, 3, 0, 0, 1 };  //коефіцієнти поліному, порядок від а[0] до a[5]
            double result = 0;
            for (int i = n; i >= 0; i--)
                result += A[i] * Math.Pow(x, i);

            return result;
        }
        static double DeprivateFunc1(double x)
        {
            int n = 4;
            int[] A = { -2, 6, 0, 0, 5 };  //беремо похідну від заданого рівняння
            double result = 0;
            for (int i = n; i >= 0; i--)
                result += A[i] * Math.Pow(x, i);

            return result;
        }
        static double DeprivateFunc2(double x)
        {
            int n = 3;
            int[] A = { 6, 0, 0, 20 };     //беремо похідну від DeprivateFunc1
            double result = 0;
            for (int i = n; i >= 0; i--)
                result += A[i] * Math.Pow(x, i);

            return result;
        }
        static void MethodBisection(double interval1, double interval2, double e)   //Метод бісекції
        {
            int counter = 0;    //лічильник, за яким рахуємо кількість ітерацій
            double x;
            if (Func(interval1) == 0) x = interval1;
            else if (Func(interval2) == 0) x = interval2;    //дано два кінці інтервалу
            else
            {
                double c = 0;
                while (Math.Abs(interval2 - interval1) > e || Math.Abs(Func(c)) > e)   //| b - a | < ε та | f(xk) | < ε 
                {
                    c = (interval1 + interval2) / 2;       //на кожному кроцi iнтервал дiлять навпiл
                    if (Func(interval1) * Func(c) < 0)
                    {
                        interval2 = c;
                    }
                    else
                    {
                        interval1 = c;
                    }
                    counter++;
                }
                x = c;
            }
            Console.WriteLine("Bisection method: x={0:f6}    iterations:{1}", x, counter);
        }

        static void MethodHord(double interval1, double interval2, double e)      //метод хорд
        {
            int counter = 0;
            double x;
            x = interval1 - (interval2 - interval1) / (Func(interval2) - Func(interval1)) * Func(interval1);
            while (Math.Abs(Func(x)) > e || (Math.Abs(x - interval1) > e && Math.Abs(x - interval2) > e))   //| xk - xk-1 | < ε та | f(xk) | < ε 
            {
                if (Func(interval1) * DeprivateFunc2(interval1) > 0)   
                {
                    interval2 = x;
                    x = x - (Func(x) * (x - interval1) / (Func(x) - Func(interval1))); //c := ( a*f(b) - b*f(a)) / ( f(b) - f(a))
                }
                else
                {
                    interval1 = x;
                    x = x - (Func(x)) / (Func(interval2) - Func(x)) * (interval2 - x); 
                }
                counter++;
            }
            Console.WriteLine("Chord method: x={0:f6}    iterations:{1}", x, counter);   //залишають той пiдiнтервал, до якого належить корiнь
        }
        static void MethodNewton(double interval1, double interval2, double e)   //Метод Ньютона (дотичних)
        {
            int counter = 1;        //лічильник ітерацій
            double x, x0 = 0;       //початкове наближення х0
            if (Func(interval1) * DeprivateFunc2(interval1) > 0) x0 = interval1;    //якщо f(a)⋅f(b)>0 ,то x0 це перше наближення до розв'язку
            else x0 = interval2;
            x = x0 - Func(x0) / DeprivateFunc1(x0);       //xk+1 := xk - f(xk) / f '(xk)
            while (Math.Abs(x - x0) > e || Math.Abs(Func(x)) > e)   //| xk - xk-1 | < ε та | f(xk) | < ε 
            {
                counter++;
                x0 = x;                             
                x = x0 - Func(x0) / DeprivateFunc1(x0);     //xk+1 := xk - f(xk) / f '(xk)
            }
            Console.WriteLine("Newton Method: x={0:f6}    iterations:{1}", x, counter);
        }
    }
}

