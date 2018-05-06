///// SMALLEST NUMBER DIVISIBLE BY ALL NUMBERS FROM 1 TO 20 /////

#include "Base.h"


static void Description_5()
{
	LOG("Find the smallest number divisible by all the numbers from 1 to 20.\n");
}

unsigned int Problem_5()
{
	Description_5();

	unsigned int current_number = 1u;
	std::vector<unsigned int> target_divisors = { 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u };
	bool broken = false;

	while (true)
	{
		broken = false;

		for (unsigned int divisor : target_divisors)
		{
			if (current_number % divisor != 0)
			{
				broken = true;
				break;
			}
		}

		if (!broken)
		{
			return current_number;
		}

		current_number += 1;
	}
}
