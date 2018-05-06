///// 10001ST PRIME NUMBER /////

#include "Base.h"


static void Description_7()
{
	LOG("Find the 10,001st prime number.\n");
}

static bool IsPrime(unsigned int number)
{
	if (number == 2)
	{
		return true;
	}

	if (number == 0 || number == 1 || number % 2 == 0)
	{
		return false;
	}

	for (unsigned int i = 3; i <= sqrt(number); i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

static unsigned int GetNextPrime(unsigned int from_number)
{
	while (true)
	{
		from_number += 1;

		if (IsPrime(from_number))  // Uses function "IsPrime(long long int number)" from Problem #3
		{
			return from_number;
		}
	}
}

unsigned int Problem_7()
{
	Description_7();

	unsigned int target_amount = 10001u;
	unsigned int next_prime = 1;

	for (unsigned int i = 1u; i <= target_amount; i++)
	{
		next_prime = GetNextPrime(next_prime);
	}

	return next_prime;
}
