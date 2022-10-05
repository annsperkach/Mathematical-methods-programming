#include "Header.h"

int main()
{
	string Str = "MilkShakeIt";
	Symbols First(Str);
	cout << Str << endl;
	cout << First.Length() << endl;
	First.Decrement();
	cout << First.GetData() << "\n\n";

	Str = "Amsterdam";
	Numbers Second(Str);
	cout << Str << endl;
	cout << Second.Length() << endl;
	Second.Decrement();
	cout << Second.GetData() << "\n\n";
}

