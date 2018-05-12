///// FIND THE SUM OF THE DIGITS IN 2^1000 /////


#include "Base.h"

static void Description_16()
{
	LOG("Find the sum of all the digits in 2^1000.\n");
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

InfInt Problem_16()
{
	Description_16();

	//double target_number = pow(2, 15);
	//long long int total = 0;
	//std::string string_number = std::to_string(target_number);

	/*
	for (char character : string_number)
	{
		long long int num = character - (int)"0";
		total += num;
	}

	return total;
	*/

	/*
	unsigned long long int target_number = pow(2, 1000);
	unsigned long long int total = 0;

	while (target_number > 0)
	{
		total += target_number % 10;
		target_number /= 10;
	}

	return total;
	*/

	InfInt target_number = Raise(2, 1000);
	InfInt total = 0;

	for (int i = 0; i < target_number.numberOfDigits(); i++)
	{
		total += target_number.digitAt(i);
	}

	return total;
}