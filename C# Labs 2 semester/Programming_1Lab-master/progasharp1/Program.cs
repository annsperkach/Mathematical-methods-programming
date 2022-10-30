using System;

namespace progasharp1
{
    class Program
    {
        static void Decreased(ref int decr)
        {
            int mask = 1;
            while ((decr & mask) == 0)
            {
                decr ^= mask;
                mask <<= 1;
            }
            decr ^= mask;
        }

        static int Compare(int num1, int num2)
            {
            int size = sizeof(int) * 8 - 1;
            int bitN1 = (num1 >> size) & 1, bitN2 = (num2 >> size) & 1;
                if (bitN1 == 1 && bitN2 == 0)
                    return 0;
                else if (bitN1 == 0 && bitN2 == 1)
                    return 1;
                else
                {
                    for (int i = size; i >= 0; i--) 
                    {
                        bitN1 = (num1 >> i) & 1;  
                        bitN2 = (num2 >> i) & 1; 
                        if (bitN1 != bitN2 && bitN1 == 1)
                            return 1;
                        else if (bitN1 != bitN2)
                            return 0;
                    }
                }
                return 0;
            }

        static void Main(string[] args)
        {
            int decr = Convert.ToInt32(Console.ReadLine());
            Decreased(ref decr);
            Console.WriteLine(decr);


            int num1 = Convert.ToInt32(Console.ReadLine());
            int num2 = Convert.ToInt32(Console.ReadLine());

            int result = Compare(num1, num2);
            if (result == 0)
            {
                Console.WriteLine(num1 + " < " + num2);
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine(num1 + " < " + num2);
                Console.WriteLine("False");
            }
            Console.ReadKey();
        }
    }
}