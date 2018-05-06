///// LARGEST PRIME FACTOR OF 600,851,475,143 /////

#include "Base.h"


static void Description_3()
{
	LOG("Find the largest prime factor of 600,851,475,143.\n");
}

inline static bool IsFactorOf(long long int factor, long long int number)
{
	return number % factor == 0;
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

long long int Problem_3()
{
	Description_3();

	long long int target_number = 600851475143LL;
	long long int factor = 2;
	long long int last_factor = 1;

	if (target_number % 2 == 0)
	{
		target_number /= 2;
		last_factor = 2;

		while (target_number % 2 == 0)
		{
			target_number /= 2;
		}
	}

	else
	{
		last_factor = 1;
	}

	factor = 3;

	while (target_number > 1)
	{
		if (target_number % factor == 0)
		{
			last_factor = factor;
			target_number /= factor;

			while (target_number % factor == 0)
			{
				target_number /= factor;
			}
		}

		factor += 2;
	}

	return last_factor;
}
