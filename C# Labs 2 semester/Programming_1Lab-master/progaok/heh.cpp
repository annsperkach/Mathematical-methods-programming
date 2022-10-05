#include "heh.h"

void Decreased(int& decr)  
{
    int mask = 1;
    while ((decr & mask) == 0)
    {
        decr ^= mask;
        mask <<= 1;
    }
    decr ^= mask;
}

bool  Compare(int num1, int num2) //функція, що порівнює два цілих числа на бітовому рівні
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


