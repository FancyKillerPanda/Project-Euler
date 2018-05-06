///// SUM OF ALL MULTIPLES OF 3 AND 5 BELOW 1000 /////

#include "Base.h"


static void Description_1()
{
	LOG("Find the sum of all the multiples of 3 or 5 below 1000.\n");
}

int Problem_1()
{
	Description_1();

	int sum = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}
