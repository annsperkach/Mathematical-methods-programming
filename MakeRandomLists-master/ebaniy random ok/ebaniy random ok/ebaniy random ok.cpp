#include <iostream>
#include <string>
#include<vector>
#include <ctime>


using namespace std;

int getRandomNumber(int, int);
void output(vector<string>);


vector<string> list =
{
"Абрамчук Павло",
"Адамов Денис",
"Бойко Олег",
"Боярчук Марiя",
"Бутирський Олег",
"Василiв Богдан",
"Возняк Софiя",
"Волков Дмитро",
"Гусак Михайло",
"Даньков Артем",
"Дон Василь",
"Дудукчян Карина",
"Зєнцов Владислав",
"Катанов Дмитро",
"Клеба Олександра",
"Коберник Юлiя",
"Коваль Вадим",
"Колосенко Анна",
"Косюк Олексiй",
"Копайгородська Дар'я",
"Кубай Дмитро",
"Макарчук Павло",
"Меркур'єв Олег",
"Мiхненко Анна",
"Прунь Артем",
"Рибчинський Назарiй",
"Серветнiк Богдан",
"Сперкач Анна",
"Стеблина Дмитро",
"Толмачов Антон",
"Трачук Юлiя",
"Удачин Артем",
"Яцюк Сергiй",
};



int main()
{
	vector<string> group_1;
	vector<string> group_2;
	setlocale(LC_ALL, "Ukr");
	int integer = 0;
	srand(static_cast<unsigned int>(time(0)));
	while ((group_1.size() == 17 && group_2.size() == 16) || !(group_1.size() == 16 && group_2.size() == 17))
	{
		group_1.clear();
		group_2.clear();
		for (int i = 0; i < 33; i++)
		{
			integer = getRandomNumber(1, 2);
			if (integer == 1)
			{
				group_1.push_back(list[i]);
			}
			else if (integer == 2)
			{
				group_2.push_back(list[i]);
			}
		}
	}
	cout << "Пiдгрупа №1:" << endl;
	output(group_1);
	cout << "_____________________________________" << endl;
	cout << "Пiдгрупа №2:" << endl;
	output(group_2);
	return 0;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void output(vector<string> a)
{
	for (auto const& element : a)
		std::cout << element << endl;
}

