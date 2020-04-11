#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

class Game
{
	int number;				// загаданное число
	int masOfNumeral[3];
public:
	Game() { number = randomUnit(); }

	bool check(int mas[3], int user)
	{
		int mas_user[3];
		for (int i = 2; i >= 0; --i)
		{
			mas_user[i] = user % 10;
			user /= 10;
		}
		int numbOfPlaced = 0;
		cout << "Число угаданных: " << chislo_ugaddanih(mas, mas_user) << ' ';
		for (int i = 0; i < 3; ++i)
		{
			if (mas[i] == mas_user[i])
			{
				numbOfPlaced++;
			}
		}
		cout << "На своих местах: " << numbOfPlaced << endl;
		if (numbOfPlaced == 3)
		{
			cout << "Good job, you won";
			return true;
		}
		return false;
	}
	void play()
	{
		cout << "Игра угадай число /n";
		cout << "Компьютер загадал трехзначное число" << endl;
		cout << "Попробуй угадать его :)" << endl;
		int userNumb;
		vvod_chisla();
		cout << "Введи свое число: " << endl;
		cin >> userNumb;
		while (!check(masOfNumeral, userNumb))
		{
			cout << "Попробуй ещё раз: " << endl;
			cin >> userNumb;
		}
	}
	int randomUnit()
	{
		int numb;
		numb = 100 + rand() % 999;
		return numb;
	}
	int chislo_ugaddanih(int mas[3], int user[3])
	{
		int k = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (user[i] == mas[j])
					k++;
		return k;
	}
	void vvod_chisla()
	{
		for (int i = 2; i >= 0; --i)
		{
			masOfNumeral[i] = number % 10;
			number /= 10;
		}
	}
	int getNumber() { return number; }
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	Game table;
	cout << table.getNumber() << endl;
	table.play();
}

