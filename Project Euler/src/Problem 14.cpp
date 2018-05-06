///// LONGEST COLLATZ SEQUENCE FROM A STARTING NUMBER BELOW 1,000,000 /////


#include "Base.h"

static void Description_14()
{
	LOG("Find the longest Collatz sequence from a starting number below 1,000,000.\n");
}

unsigned int CollatzLength(unsigned int number)
{
	unsigned int length = 1;

	while (number != 1)
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}

		else
		{
			number = number * 3 + 1;
		}

		length += 1;
	}

	return length;
}

unsigned int Problem_14()
{
	Description_14();
	
	unsigned int target_number = 1000000U;
	unsigned int max_length = 0;
	unsigned int max_number;
	unsigned int length;

	for (unsigned int i = 1; i < target_number; i++)
	{
		length = CollatzLength(i);

		if (length > max_length)
		{
			max_length = length;
			max_number = i;
		}
	}

	return max_number;
}
