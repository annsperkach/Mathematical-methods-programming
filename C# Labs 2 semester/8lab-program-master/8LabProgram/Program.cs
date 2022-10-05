using System;
using Library;

namespace _8LabProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            DoubleList list = new DoubleList();
            list.FirstAdd(13.5);
            list.FirstAdd(5.5);
            list.FirstAdd(333);
            list.FirstAdd(2.5); 
            list.FirstAdd(1.57);
            list.FirstAdd(23);
            list.FirstAdd(214.5);

            foreach (var l in list)
            {
                Console.Write(l + "  ");
            }
            Console.WriteLine();
            Console.WriteLine(list.Sum() / list.Size);
            Console.WriteLine(list.LessThanAverage());
            Console.WriteLine(list.Sum());
            Console.WriteLine(list.MaxNode());
            list.DeleteToMax();
            foreach (var l in list)
            {
                Console.Write(l + "  ");
            }
            Console.WriteLine();
        }
    }
}
