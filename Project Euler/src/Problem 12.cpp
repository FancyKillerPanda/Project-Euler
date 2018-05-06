///// FIRST TRIANGULAR NUMBER TO HAVE OVER 500 DIVISORS /////

#include "Base.h"


static void Description_12()
{
	LOG("Find the first triangular number to have over 500 divisors.\n");
}

static std::vector<long long int> GetFactors(long long int number)
{
	std::vector<long long int> factors;

	for (long long int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			factors.push_back(i);
		}
	}

	return factors;
}

long long int Problem_12()
{
	Description_12();

	long long int target_divisors = 5;
	long long int next_num = 0;
	long long int number_to_add = 1;
	std::vector<long long int> factors;


	while (true)
	{
		next_num += number_to_add;
		factors = GetFactors(next_num);

		if ((long long)factors.size() >= target_divisors)
		{
			return next_num;
		}

		number_to_add += 1;
	}
}
