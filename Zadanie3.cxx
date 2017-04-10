// Zadanie3
//Napisz program symuluj¹cy grê w koœci.
//W grze bierze udzia³ dwóch graczy o nazwach : pierwszy, drugi.
//Ka¿demu graczowi przypada 5 tur.Tury graczy odbywaj¹ siê naprzemiennie

#include "stdafx.h"
#include <random>
#include <conio.h>
#include <iostream>

double throwdice(int throws)
{
	double result = 0;
	static std::mt19937 engine(std::time(nullptr));
	static std::uniform_int_distribution<> distribution(1, 6);
	auto dice = [&]() { return distribution(engine); };

	for (int i = 1; i <= throws; i++)
	{
		double sum = 0;
		sum = dice() + dice();
		if(i==1 && (sum==7 || sum==11))
		{
			break;
		}
		else if(i == 1 && (sum==2 || sum==12))
		{
			for (int j = 1; j <= throws; j++)
			{
				result = result + 12 / (double)j;
			}
			break;
		}
		else if (sum == 5)
		{
			break;
		}
		result = result + sum/ (double)i;
	}
	return result;	
}

int main()
{
	int round = 1;
	double resultP1 = 0;
	double resultP2 = 0;
	do
	{
		resultP1 = throwdice(10) + resultP1;
		resultP2 = throwdice(10) + resultP2;
		round++;
	} while (round < 6);
	std::cerr << "Gra zakonczona, uzyskane punkty: pierwszy("<< resultP1 <<"), drugi(" << resultP2 << ")" << std::endl;
	if (resultP1 > resultP2)
	{
		std::cerr << "Wygrywa drugi" << std::endl;
	}
	else if(resultP2 > resultP1)
	{
		std::cerr << "Wygrywa pierwszy" << std::endl;
	}
	else
	{
		std::cerr << "Remis" << std::endl;
	}
	_getch();
    return 0;
}

