///// LATTICE PATHS ON A 20 X 20 GRID /////


#include "Base.h"
#include <bitset>

static void Description_15()
{
	LOG("Find the number of Lattice paths on a 20x20 grid.\n");
}

static InfInt Raise(int number, int exponent)
{
	if (exponent == 0)
	{
		return InfInt(1);
	}

	InfInt value = 1;

	for (int i = 0; i < exponent; i++)
	{
		value *= number;
	}

	return value;
}

static InfInt Factorial(InfInt number)
{
	InfInt total = 1;

	if (number <= 1)
	{
		return 1;
	}

	for (InfInt i = 2; i <= number; i++)
	{
		total *= i;
	}

	return total;
}

InfInt Problem_15()
{
	Description_15();

	/*
	InfInt grid_size = 4;
	InfInt path_length = grid_size * 2;
	InfInt max_num = Raise(10, path_length.toInt());
	InfInt total_paths = 0;

	for (InfInt i = 0; i < max_num;)
	{
		std::string num_str = std::to_string(i.toLongLong());

		if (num_str.find_first_not_of("01") != std::string::npos)
		{
			if (i >= 10 && i % 10 == 1)
			{
				i += 9;
			}

			else
			{
				i += 1;
			}

			continue;
		}

		auto count = std::count(num_str.begin(), num_str.end(), '1');

		if (count != grid_size.toInt())
		{
			if (i >= 10 && i % 10 == 1)
			{
				i += 9;
			}

			else
			{
				i += 1;
			}

			continue;
		}

		total_paths += 1;

		if (i >= 10 && i % 10 == 1)
		{
			i += 9;
		}

		else
		{
			i += 1;
		}
	}

	return total_paths;
	*/

	/*
	const int grid_size = 3;
	const int path_length = grid_size * 2;
	int total_paths = 0;
	std::string bin_num;

	for (int i = 0; i < pow(2, path_length); i++)
	{
		bin_num = std::bitset<path_length>(i).to_string();

		auto count = std::count(bin_num.begin(), bin_num.end(), '1');

		if (count == grid_size)
		{
			total_paths += 1;
		}
	}

	return total_paths;
	*/

	const InfInt grid_size = 20;
	const InfInt path_length = grid_size * 2;
	
	InfInt total = (Factorial(path_length) / Factorial(grid_size)) / (Factorial(grid_size));

	return total;
}
