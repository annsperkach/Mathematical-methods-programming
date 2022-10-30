#include "Header.h"
Symbols::Symbols(string _str)
{
	str = _str;
}

int Symbols::Length()
{
	return str.length();
}

void Symbols::Decrement()
{
    string NewStr = "";
    int count = 1;
    while (str[count] != '\0')
    {
        NewStr += str[count];
        ++count;
        if (str[count] == '\0')
        {
            break;
        }
        ++count;
    }
    str = NewStr;
}

string Symbols::GetData()
{
	return str;
}

Numbers::Numbers(string _str)
{
	str = _str;
}

int Numbers::Length()
{
	return str.length();
}

void Numbers::Decrement()
{
    string NewStr = "";
    int count = 0;
    while (str[count] != '\0')
    {
        NewStr += str[count];
        ++count;
        if (str[count] == '\0')
        {
            break;
        }
        ++count;
    }
    str = NewStr;
}

string Numbers::GetData()
{
	return str;
}