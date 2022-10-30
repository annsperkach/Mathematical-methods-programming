#include "heh.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int decr;
	cin >> decr;
	Decreased(decr);
	cout << decr << endl;

	int num1, num2;
	cin >> num1 >> num2;
	int comparison;
	comparison = Compare(num1, num2);
	if (comparison == 0)
	{
		cout << num1 << " < " << num2 << endl;
		cout << "True";
	}
	else
	{
		cout << num1 << " < " << num2 << endl;
		cout << "False";
	}
	system("pause");
}

