///// DIFFERENCE BETWEEN SUM OF SQUARES AND SQUARE OF SUMS FOR FIRST 100 INTEGERS /////

#include "Base.h"


static void Description_6()
{
	LOG("Find the difference between the square of the sums and the sum of the squares for");
	LOG("the first 100 integers.\n");
}

unsigned int Problem_6()
{
	Description_6();

	unsigned int target_start = 1u;
	unsigned int target_end = 100u;
	unsigned int sum_of_squares = 0u;
	unsigned int sum_of_numbers = 0u;
	unsigned int square_of_sums = 0u;

	for (unsigned int i = target_start; i <= target_end; i++)
	{
		sum_of_squares += i * i;
	}

	for (unsigned int i = target_start; i <= target_end; i++)
	{
		sum_of_numbers += i;
	}

	square_of_sums = sum_of_numbers * sum_of_numbers;

	return square_of_sums - sum_of_squares;
}
