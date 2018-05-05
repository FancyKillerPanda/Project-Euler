#include <iostream>
#include <vector>
#include <string>

#define LOG(x) std::cout << x << std::endl
#define CLEAR system("CLS")
#define WAIT std::cout << std::endl; system("PAUSE")

int Problem_1();
int Problem_2();
long long int Problem_3();
unsigned int Problem_4();
unsigned int Problem_5();
unsigned int Problem_6();
unsigned int Problem_7();
long long int Problem_8();
unsigned int Problem_9();
long long int Problem_10();
long long int Problem_12();


int main()
{	
	while (true)
	{
		CLEAR;
		std::string input = "";
		int int_input;

		LOG("\u001b[34;1mWhat Problem Would You Like?\u001b[0m");
		std::getline(std::cin, input);
		CLEAR;

		try
		{
			int_input = std::stoi(input);
		}

		catch (const std::exception&)
		{
			LOG("Sorry, that's not a valid number.");
			WAIT;
			continue;
		}

		switch (int_input)
		{
		case 1:
			LOG(Problem_1());
			WAIT;

			break;

		case 2:
			LOG(Problem_2());
			WAIT;

			break;

		case 3:
			LOG(Problem_3());			
			WAIT;

			break;

		case 4:
			LOG(Problem_4());
			WAIT;

			break;

		case 5:
			LOG(Problem_5());
			WAIT;

			break;

		case 6:
			LOG(Problem_6());
			WAIT;

			break;

		case 7:
			LOG(Problem_7());
			WAIT;

			break;

		case 8:
			LOG(Problem_8());
			WAIT;

			break;

		case 9:
			LOG(Problem_9());
			WAIT;

			break;

		case 10:
			LOG(Problem_10());
			WAIT;

			break;

		case 12:
			LOG(Problem_12());
			WAIT;

			break;

		default:
			LOG("Sorry, that's not a valid problem number.");
			WAIT;

			break;
		}
	}
}