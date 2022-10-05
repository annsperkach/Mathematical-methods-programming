#include <iomanip>
#include <windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double AMount, amount;
	double comp = 0;
	system("color E0"); //колір консолі
	SetConsoleCP(1251);   //налаштування української мови
	SetConsoleOutputCP(1251);
	double bMat[5] = { 6.89, 3.21, 3.58, 6.25, 5.65 };
	amount = 6;
	AMount = pow(10, -1 * amount);
	double Mat[5][6] = {
	{5.68, 1.12, 0.95, 1.32, 0.83, 6.89},
	{1.12, 3.78, 2.12, 0.57, 0.91, 3.21},
	{ 0.95, 2.12, 6.63, 1.29, 1.57, 3.58},
	{ 1.32, 0.57, 1.29, 4.07, 1.25, 6.25},
	{ 0.83, 0.91, 1.57, 1.25, 5.71, 5.65}
	};
	double NewMat[5][6] = {
	{5.68, 1.12, 0.95, 1.32, 0.83, 6.89},
	{1.12, 3.78, 2.12, 0.57, 0.91, 3.21},
	{ 0.95, 2.12, 6.63, 1.29, 1.57, 3.58},
	{ 1.32, 0.57, 1.29, 4.07, 1.25, 6.25},
	{ 0.83, 0.91, 1.57, 1.25, 5.71, 5.65}
	};
	bool b = true;
	double tmp;
	int i, j = 0;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << endl << "	Наша матриця:" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			cout << setw(9) << Mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "___________________________________________________" << endl;
	cout << endl << "	Матриця у вигляді системи:" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << "	" << Mat[i][j] << "*x" << j + 1;
			if (j == 4)
			{
				cout << " = " << Mat[i][5] << endl;
			}
			else
			{
				cout << " + ";
			}
		}
	}



	double chang;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << endl << "	Матриця після ділення на головну діагональ:" << endl;

	for (int i = 0; i < 5; i++)
	{
		chang = Mat[i][i];
		for (int j = 0; j < 6; j++)
		{
			Mat[i][j] = Mat[i][j] / chang;
			cout << setw(9) << Mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << "___________________________________________________" << endl;
	cout << endl << "	Матриця після зведення до трикутного вигляду:" << endl;

	for (i = 0; i < 5; i++)
	{
		tmp = Mat[i][i];
		for (int j = 5; j >= i; j--)
			Mat[i][j] /= tmp;
		for (int j = i + 1; j < 5; j++)
		{
			tmp = Mat[j][i];
			for (int k = 5; k >= i; k--)
				Mat[j][k] -= tmp * Mat[i][k];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << setw(9) << Mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << endl << "	Матриця після перестановки першого елементу на головній діагоналі:" << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << Mat[i][i] << "	x" << i + 1 << " = ";
		for (int j = 0; j < 6; j++)
		{
			if (i != j)
			{
				if (j != 5)
				{
					cout << -Mat[i][j] << "	x" << j + 1;
				}
				else
				{
					cout << " + " << Mat[i][j] << "x";
				}
			}
		}
		cout << endl;
	}

	double vect[5];
	for (int i = 0; i < 5; i++)
	{
		vect[i] = Mat[i][5];
	}
	int n = 0;


	while (b)
	{
		n++;
		cout << "___________________________________________________" << endl;
		cout << endl << "                        " << "Ітерація №: " << n << "                         " << endl;
		cout << endl << "		Вектор b:" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "	(" << vect[i] << ")" << endl;
		}
		double second[5];
		for (int i = 0; i < 5; i++) second[i] = 0;
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl << "	Після перетворення вектора b " << n << " раз                        " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << Mat[i][i] << "	x" << i + 1 << " = ";
			for (int j = 0; j < 6; j++)
			{
				if (i != j)
				{
					if (j != 5)
					{
						if (Mat[i][j] * vect[j] > 0)
						{

							cout << " - (" << Mat[i][j] << ") * (" << vect[j] << ")";
						}
						else
						{
							cout << " + (" << Mat[i][j] << ") * (" << vect[j] * (-1) << ")";
						}

					}
					else
					{
						cout << " + (" << Mat[i][j] << ")";
					}
				}
			}
			cout << endl;
		}
		cout << "___________________________________________________________" << endl;
		cout << endl << "" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << Mat[i][i] << "	x" << i + 1 << " = ";
			for (int j = 0; j < 6; j++)
			{
				if (i != j)
				{
					if (j != 5)
					{
						if (Mat[i][j] * vect[j] > 0)
						{
							cout << " (" << Mat[i][j] * (-1) * vect[j] << ") ";
							second[i] += -1 * Mat[i][j] * vect[j];
						}
						else
						{
							cout << " + (" << Mat[i][j] * (-1) * vect[j] << ")";
							second[i] += -1 * Mat[i][j] * vect[j];
						}
					}
					else
					{
						cout << " + (" << Mat[i][j] << ")";
						second[i] += Mat[i][j];
					}
				}
			}
			cout << endl;
		}

		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl << "	Результат: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "	x" << i + 1 << " = " << round(second[i] * 1000000) / 1000000 << endl;
			vect[i] = second[i];
		}
		/////////////
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << "Порівняння ітерацій:" << endl;
		if (comp != 0)
		{
			cout << "|" << round(comp * 10000) / 10000 << "- (" << round(second[3] * 10000) / 10000 << ")|=" << round(abs(comp - second[3]) * 10000) / 10000 << endl;
			if (abs(comp - second[3]) < AMount)
			{
				b = false;
			}
		}
		comp = second[3];

		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << "	Вектор нев'язки:\n";
		cout << endl << "	r = {";
		double r[5];
		double VectorR[5];
		for (int i = 0; i < 5; i++)
		{
			r[i] = NewMat[i][5];
			for (int j = 0; j < 5; j++)
			{
				r[i] -= NewMat[i][j] * second[j];
			}
			VectorR[i] = bMat[i] - r[i];
			cout << round(r[i] * 1000000) / 1000000 << " ";
		}
		cout << "}" << endl;

	}
	system("pause");
	return 0;
}
