// Zadanie1
//Napisz program, kt�ry wypisuje liczby od 1 do 100. 
//Ale dla wielokrotno�ci tr�jki wy�wietl "Fizz" zamiast liczby 
//oraz dla wielokrotno�ci pi�tki wy�wietl "Buzz". 
//Dla liczb b�d�cych wielokrotno�ciami tr�jki oraz pi�tki wy�wietl "FizzBuzz".

#include "stdafx.h"
#include <conio.h>
#include <iostream>

bool isrepeatabilityof3(int i)
{
	if (i % 3 == 0) { return true; }
	else { return false; }
}

bool isrepeatabilityof5(int i)
{
	if (i % 5 == 0) { return true; }
	else { return false; }
}

void isrepeatability(int i)
{
	if (isrepeatabilityof3(i) && isrepeatabilityof5(i))
	{
		std::cerr << "FizzBuzz" << std::endl;
	}
	else if(isrepeatabilityof3(i))
	{
		std::cerr << "Fizz" << std::endl;
	}
	else if (isrepeatabilityof5(i))
	{
		std::cerr << "Buzz" << std::endl;
	}
	else
	{
		std::cerr << i << std::endl;
	}
}

void numarate(int startN, int endN)
{
	int i;
	for (i = startN; i <= endN; i++)
	{
		isrepeatability(i);
	}	
}

int main()
{
	numarate(1, 100);
	_getch();
    return 0;
}



