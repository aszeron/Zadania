// Zadanie2
//Napisz funkcjê sprawdzaj¹c¹ poprawnoœæ daty w latach 2001-2099 
//(daty spoza tego okresu uznaj za niepoprawne).
//Wejœcie – trzy parametry liczbowe(dzieñ, miesi¹c, rok).
//Wyjœcie – parametr logiczny(true – data poprawna, false – data niepoprawna) .

#include "stdafx.h"

bool correctness(int D, int M, int Y)
{
	if (D <= 0 || D > 31 || M <= 0 || M > 12 || Y < 2001 || Y>2099)
	{
		return false;
	}
	else if ((M == 4 || M == 6 || M == 9 || M == 11) && D == 31)
	{
		return false;
	}
	else if (M == 2 && D > 28)
	{
		if (D==29 && Y % 4 == 0)
		{
			return true;
		}
		else { return false; }
	}	
	else { return true; }
}

int main()
{
	correctness(29, 2, 2008);
    return 0;
}

