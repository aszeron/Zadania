// Zadanie4
//Celem zadania jest napisanie funkcji sprawdzaj¹cej, 
//czy podany tekst jest kodem kreskowym EAN-13 lub EAN-8.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>

std::string add0(std::string code)
{
	code = "0" + code;
	return code;
}

std::string removelast(std::string code, int type)
{
	int cut = code.size();
	if (type == 1) {cut = cut - 8;}
	else { cut = cut - 13; }
	code = code.substr(0, code.size() - cut);
	return code;
}

std::string barcode(std::string code, int type)
{
	int lgh = code.length();

	if((type==1 && lgh == 7) || (type==2 && lgh == 12))
	{throw 0;}

	if ((type == 1 && lgh > 8) || (type == 2 && lgh > 13))
	{throw 1;}

	if (type != 1 && type != 2)
	{throw 2;}

	if ((type == 1 && lgh < 7) || (type == 2 && lgh < 12))
	{throw 3;}

	return code;
}

int main()
{
	std::string code = "692070270773562";
	int lgh = code.length();
	int type = 2;

	try
	{
		code = barcode(code, type);
	}
	catch (int error)
	{
		if (error == 0)
		{
			code = add0(code);
			std::cerr << "ERROR" << error << ": Za krotki kod! Prawdopodobnie zostalo usuniete pierwsze 0." << std::endl;
		}

		if (error == 1)
		{
			code = removelast(code, type);
			std::cerr << "ERROR" << error << ": Za dlugi kod! Prawdopodobnie zostalo dodany add-on." << std::endl;
		}

		if (error == 2)
		{
			std::cerr << "ERROR" << error << ": Nieznany typ kodowania!" << std::endl;
		}

		if (error == 3)
		{
			std::cerr << "ERROR" << error << ": Za krotki kod!" << std::endl;
		}		
		
	}
	std::cerr << "Nowy kod: " << code << std::endl;
	_getch();
    return 0;
}

