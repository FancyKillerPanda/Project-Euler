///// SUM OF EVEN FIBONACCI NUMBERS BELOW 4,000,000 /////

#include "Base.h"


static void Description_2()
{
	LOG("Find the sum of the even-valued Fibonacci sequence terms less than 4,000,000.\n");
}

int Problem_2()
{
	Description_2();

	int sum = 0;
	int a = 1;
	int b = 2;
	int c;

	while (true)
	{
		if (a % 2 == 0)
		{
			sum += a;
		}

		c = a + b;
		a = b;
		b = c;

		if (a > 4000000)
		{
			break;
		}
	}

	return sum;
}
