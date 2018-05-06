///// LARGEST PALINDROME FROM THE PRODUCT OF TWO 3 DIGIT NUMBERS /////

#include "Base.h"


static void Description_4()
{
	LOG("Find the largest palindrome product of two 3 digit numbers.\n");
}

static bool IsPalindrome(unsigned int number)
{
	std::string string_number = std::to_string(number);
	std::string reversed;

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
