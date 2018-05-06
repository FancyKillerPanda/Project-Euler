///// SUM OF ALL PRIMES BELOW 2,000,000 /////

#include "Base.h"


static void Description_10()
{
	LOG("Find the sum of all the prime numbers below 2,000,000.\n");
}

static bool IsPrime(long long int number)
{
	if (number == 2)
	{
		return true;
	}

	if (number == 0 || number == 1 || number % 2 == 0)
	{
		return false;
	}

	for (long long int i = 3; i <= sqrt(number); i++)
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

long long int Problem_10()
{
	Description_10();

	long long int target_num = 2000000LL;
	long long int total = 2LL;

	for (long long int i = 3; i < target_num; i += 2)
	{
		if (IsPrime(i))
		{
			total += i;
		}
	}

	return total;
}
