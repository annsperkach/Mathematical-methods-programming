#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
using namespace std;

int main()
{
	system("color E0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//наша матриця
	double A[4][4] = {
	{7.14,   1.26,   0.81,   1.12},
	{1.26,   3.28,   1.30,   0.16},
	{0.81,   1.30,   6.32,   2.10},
	{1.12,   0.16,   2.10,   5.22},
	};

	cout << "Матриця А:" << endl;   //виводимо задану матрицю
	for (int k = 0; k < 4; k++)
	{
		for (int m = 0; m < 4; m++) 
		{
			cout << setw(5) << " " << A[k][m] << " " << " ";
	    }
		cout << endl;
	}
	cout << endl;

	double M1[4][4];

	for (int i = 0; i <= 2; i++)
	{
		//одиничні матриці
		double F1[4][4]= { { 1,	0,	0,	0 },{ 0,	1,	0,	0 },{ 0,	0,	1,	0 },{ 0,	0,	0,	1 } };
		double F2[4][4]= { { 1,	0,	0,	0 },{ 0,	1,	0,	0 },{ 0,	0,	1,	0 },{ 0,	0,	0,	1 } };

		//Метод Данилевського
		for (int j = 0; j < 4; j++)
		{
			if (j != 2 - i) {
				F1[2 - i][j] = -(A[2 - i + 1][j]) / (A[2 - i + 1][2 - i]);
			}
			else
			{
				F1[2 - i][j] = 1 / A[2 - i + 1][2 - i];
			}
			F2[2 - i][j] = A[3 - i][j];
		}
			cout << "__________________________________________________________________________________" << endl;
			cout << "Матриця М1 на ітерації №"<< i << endl;
			for (int k = 0; k < 4; k++) {
				for (int m = 0; m < 4; m++)
				{
					cout << setw(5) << " " << F1[k][m] << " " << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Матриця М1^-1 на ітерації №" << i << endl;
			for (int k = 0; k < 4; k++) {
				for (int m = 0; m < 4; m++)
				{
					cout << setw(5) << " " << F2[k][m] << " " << " ";
				}
				cout << endl;
			}
			cout << endl;
			//матриця заповнена нулями
			double K1[4][4] = { { 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 } };
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int g = 0; g < 4; g++)
					{
						K1[i][j] += F2[i][g] * A[g][j];
					}
				}
			}

			double K2[4][4] = { { 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 } };
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int g = 0; g < 4; g++)
					{
						K2[i][j] += K1[i][g] * F1[g][j];
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					A[i][j] = K2[i][j];
				}
			}

			cout << "Матриця після P після ітерації №" << i + 1 << endl;
			for (int k = 0; k < 4; k++) {
				for (int m = 0; m < 4; m++)
				{
					cout << setw(5) << " " << A[k][m] << " " << " ";
				}
				cout << endl;
			}
			cout << endl;
    }
	//завершення ітераційного циклу
	cout << endl;
	cout << "Характеристичне рівняння матриці:" << "x^4-";
	int lyambda = 3;
	for (int i = 0; i < 4; i++)
	{
		if (i != 3)
		{
			cout << "(" << A[0][i] << ")" << "*x^" << lyambda << "-";
		}
		else {
			cout << A[0][3] << ";" << endl;
		}
		lyambda--;
	}

	system("pause");
	return 0;
}