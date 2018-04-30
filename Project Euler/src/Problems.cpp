#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define LOG(x) std::cout << x << std::endl


///// [PROBLEM #1] - SUM OF ALL MULTIPLES OF 3 AND 5 BELOW 1000 /////

void Description_1()
{
	LOG("Find the sum of all the multiples of 3 or 5 below 1000.\n");
}

int Problem_1()
{
	Description_1();

	int sum = 0;

	for (int i = 0; i < 1000; i++)
	{
		/*
		if (i % 3 == 0)
		{
			sum += i;
		}

		else if (i % 5 == 0)
		{
			sum += i;
		}
		*/

		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}



///// [PROBLEM #2] - SUM OF EVEN FIBONACCI NUMBERS BELOW 4,000,000 /////

void Description_2()
{
	LOG("Find the sum of the even-valued Fibonacci sequence terms less than 4,000,000.\n");
}

int Problem_2()
{
	Description_2();
	
	int sum = 0;
	int a = 1;
	int b = 2;
	int c;

	while (true)
	{		
		if (a % 2 == 0)
		{
			sum += a;
		}

		c = a + b;
		a = b;
		b = c;
		
		if (a > 4000000)
		{			
			break;
		}
	}

	return sum;
}



///// [PROBLEM #3] - LARGEST PRIME FACTOR OF 600,851,475,143 /////

void Description_3()
{
	LOG("Find the largest prime factor of 600,851,475,143.\n");
}

bool IsFactorOf(long long int factor, long long int number)
{
	long long int int_result = number / factor;
	double double_result = (double)number / (double)factor;

	return int_result == double_result;
	//return (int)result == result;
}

bool IsPrime(long long int number)
{
	if (number == 2 || number == 3 || number == 5)
	{
		return true;
	}
	
	else
	{
		if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0)
		{
			return false;
		}
	}

	int total_hits = 0;

	for (long long int i = 1LL; i <= number; i++)
	{
		if (IsFactorOf(i, number))
		{
			total_hits += 1;

			if (total_hits > 2)
			{
				return false;
			}
		}
	}

	return true;

	/*
	if (number <= 1)
	{
		return false;
	}

	else if (number <= 3)
	{
		return true;
	}

	else if (number % 2 == 0 || number % 3 == 0)
	{
		return false;
	}

	unsigned int i = 5;

	while (i * i <= number)
	{
		if (number % i == 0 || number % (i + 2) == 0)
		{
			return false;
		}

		i += 6;
	}

	return true;
	*/
}

long long int Problem_3()
{
	Description_3();
	
	long long int target_number = 600851475143LL;
	
	for (long long i = target_number; i > 0; i--)
	{
		if (IsFactorOf(i, target_number))
		{
			if (IsPrime(i))
			{
				return i;
			}
		}
	}

	return 1;
}



///// [PROBLEM #4] - LARGEST PALINDROME FROM THE PRODUCT OF TWO 3 DIGIT NUMBERS /////

void Description_4()
{
	LOG("Find the largest palindrome product of two 3 digit numbers.\n");
}

bool IsPalindrome(unsigned int number)
{
	std::string string_number = std::to_string(number);
	std::string reversed;

	/*
	for (std::string& character : string_number)
	{
		reversed.insert(0, character);
	}
	*/

	for (int i = 0u; i < string_number.size(); i++)
	{
		reversed = string_number[i] + reversed;
	}

	return reversed == string_number;
}

unsigned int Problem_4()
{
	Description_4();
	
	std::vector<unsigned int> palindromes;

	for (unsigned int i = 999u; i > 99u; i--)
	{
		for (unsigned int j = i; j > 99u; j--)
		{
			unsigned int result = i * j;

			if (IsPalindrome(result))
			{
				palindromes.push_back(result);
			}
		}
	}

	auto it = *std::max_element(std::begin(palindromes), std::end(palindromes));
	return it;
}



///// [PROBLEM #5] - SMALLEST NUMBER DIVISIBLE BY ALL NUMBERS FROM 1 TO 20 /////

void Description_5()
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



///// [PROBLEM #6] - DIFFERENCE BETWEEN SUM OF SQUARES AND SQUARE OF SUMS FOR FIRST 100 INTEGERS /////

void Description_6()
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



///// [PROBLEM #7] - 10001ST PRIME NUMBER /////

void Description_7()
{
	LOG("Find the 10,001st prime number.\n");
}

unsigned int GetNextPrime(unsigned int from_number)
{
	while (true)
	{
		from_number += 1;

		if (IsPrime(from_number))
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