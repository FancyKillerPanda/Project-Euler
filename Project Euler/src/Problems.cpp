#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>

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
	/*
	long long int int_result = number / factor;
	double double_result = (double)number / (double)factor;

	return int_result == double_result;
	//return (int)result == result;
	*/

	return number % factor == 0;
}

bool IsPrime(long long int number)
{
	/*
	if (number == 2 || number == 3 || number == 5 || number == 7 || number == 11 || number == 13)
	{
		return true;
	}
	
	else
	{
		if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0 || number % 11 == 0 || number % 13 == 0)
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

	*/

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

	/*
	for (long long i = target_number; i > 0; i--)
	{		
		if (i == target_number)
		{
			i = target_number / 2 + 1;
		}

		else if (i == target_number / 2)
		{
			i = target_number / 3 + 1;
		}

		else if (i == target_number / 3)
		{
			i = target_number / 4 + 1;
		}
		
		else if (i == target_number / 4)
		{
			i = target_number / 5 + 1;
		}
		
		else if (i == target_number / 5)
		{
			i = target_number / 6 + 1;
		}
		
		else if (i == target_number / 6)
		{
			i = target_number / 7 + 1;
		}

	}
	*/

	/*
	for (long long int i = 3; i < target_number; i += 2)
	{
		if (target_number % i == 0)
		{
			if (IsPrime(i))
			{
				if (i > biggest_pf)
				{
					biggest_pf = i;
				}
			}
		}
	}

	return biggest_pf;
	*/

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



///// [PROBLEM #8] - LARGEST PRODUCT OF 13 CONSECUTIVE DIGITS IN A 1000 DIGIT NUMBER /////

void Description_8()
{
	LOG("Find the largest product of 13 consecutive digits in:");
	LOG("73167176531330624919225119674426574742355349194934\n"
		"96983520312774506326239578318016984801869478851843\n"
		"85861560789112949495459501737958331952853208805511\n"
		"12540698747158523863050715693290963295227443043557\n"
		"66896648950445244523161731856403098711121722383113\n"
		"62229893423380308135336276614282806444486645238749\n"
		"30358907296290491560440772390713810515859307960866\n"
		"70172427121883998797908792274921901699720888093776\n"
		"65727333001053367881220235421809751254540594752243\n"
		"52584907711670556013604839586446706324415722155397\n"
		"53697817977846174064955149290862569321978468622482\n"
		"83972241375657056057490261407972968652414535100474\n"
		"82166370484403199890008895243450658541227588666881\n"
		"16427171479924442928230863465674813919123162824586\n"
		"17866458359124566529476545682848912883142607690042\n"
		"24219022671055626321111109370544217506941658960408\n"
		"07198403850962455444362981230987879927244284909188\n"
		"84580156166097919133875499200524063689912560717606\n"
		"05886116467109405077541002256983155200055935729725\n"
		"71636269561882670428252483600823257530420752963450\n");
}

unsigned int Problem_8()
{
	Description_8();

	unsigned int target_distance = 13;
	std::string target_num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	std::vector<unsigned int> list_of_ints;
	std::vector<unsigned int> products;

	for (unsigned int i = 0; i < target_num.length(); i++)
	{
		list_of_ints.clear();

		for (unsigned int j = 0; j < target_distance; j++)
		{
			list_of_ints.push_back((unsigned int)(target_num[i + j]));
		}

		auto product = std::accumulate(std::begin(list_of_ints), std::end(list_of_ints), 1, std::multiplies<unsigned int>());
		products.push_back(product);
	}

	for (unsigned int product : products)
	{
		LOG(product);
	}
	return 0u;
}



///// [PROBLEM #9] - PYTHAGOREAN TRIPLET WHERE 'A' + 'B' + 'C' = 1000 /////

void Description_9()
{
	LOG("Find 'a' * 'b' * 'c' in a Pythagorean triplet where 'a' + 'b' + 'c' = 1000.\n");
}

unsigned int Problem_9()
{
	Description_9();

	unsigned int target = 1000U;

	for (unsigned int a = 1; a <= target - 2; a++)
	{
		for (unsigned int b = 1; b <= target - 2; b++)
		{
			for (unsigned int c = 1; c <= target - 2; c++)
			{
				if (a != 0 && b != 0 && c != 0 && a + b + c == 1000)
				{
					if (a * a + b * b == c * c)
					{
						return a * b * c;
					}
				}
			}
		}
	}

	return 0;
}



///// [PROBLEM #10] - SUM OF ALL PRIMES BELOW 2,000,000 /////

void Description_10()
{
	LOG("Find the sum of all the prime numbers below 2,000,000.\n");
}

unsigned int Problem_10()
{
	Description_10();

	unsigned int target_num = 2000000U;
	unsigned int total = 0U;
	unsigned int next_prime = 1U;

	while (true)
	{

		next_prime = GetNextPrime(next_prime);  // Uses function "GetNextPrime(unsigned int from_number)" from Problem #7

		if (next_prime < target_num)
		{
			total += next_prime;
		}

		else
		{
			return total;
		}
	}
}