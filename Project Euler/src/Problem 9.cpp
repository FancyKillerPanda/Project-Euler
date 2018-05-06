///// PYTHAGOREAN TRIPLET WHERE 'A' + 'B' + 'C' = 1000 /////

#include "Base.h"


static void Description_9()
{
	LOG("Find 'a' * 'b' * 'c' in a Pythagorean triplet where 'a' + 'b' + 'c' = 1000.\n");
}

unsigned int Problem_9()
{
	Description_9();

	unsigned int target = 1000U;

	for (unsigned int a = 1; a <= target - 2; a++)
	{
		for (unsigned int b = 1; b <= target - 2; b++)
		{
			for (unsigned int c = 1; c <= target - 2; c++)
			{
				if (a != 0 && b != 0 && c != 0 && a + b + c == 1000)
				{
					if (a * a + b * b == c * c)
					{
						return a * b * c;
					}
				}
			}
		}
	}

	return 0;
}
