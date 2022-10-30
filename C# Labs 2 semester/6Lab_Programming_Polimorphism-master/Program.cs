using System;

namespace Lab6Polymorphism
{
    class Program
    {
        static void Main()
        {
            string Str = "Strawberry";
            Symbols First = new Symbols(Str);
            Console.WriteLine(Str);
            Console.WriteLine(First.Length());
            First.Decrement();
            Console.WriteLine(First.GetData());

            Str = "Banana";
            Numbers Second = new Numbers(Str);
            Console.WriteLine(Str);
            Console.WriteLine(Second.Length());
            Second.Decrement();
            Console.WriteLine(Second.GetData());
        }
    }
}
