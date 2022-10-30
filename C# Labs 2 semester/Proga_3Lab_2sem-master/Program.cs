using System;
using MyLibrary;

namespace _3Lab_Program_Indexator
{
    class Program
    {
        static void Main(string[] args)
        {
            MyString Container = new MyString();
            Container.AddString("Hello");
            Container.AddString("My");
            Container.AddString("Dear");


            Container.ControlAccess();
            Container[0] = "0 cell";

            for (int i = 0; i < Container.Length; i++)
            {
                Console.WriteLine(Container[i]);
            }
        }
    }
}
