#include <iostream>

const char* first_digit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char* teens_digit[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* second_digit[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char* third_digit[] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};
const char fourth_digit[] = {"one thousand"};


void num_word(int n) 
{
	if (n == 1000) 
	{
		std::cout << fourth_digit;
	}
	else if ((n <= 999 && n >= 100) 
	{
		std::cout << third_digit[n];
	}
	else if (n <= 99 && n >= 20) 
	{
		std::cout << second_digit[n];
	}
	else if (n <= 19 && n >= 10)
			
	return 0;
}

int main() 
{
	while(1) 
	{
		int n;
		std::cout << "Enter n:";
		std::cin >> n;
		const char* fin_word = num_word(n);
		std::cout << fin_word << '\n';
	}
}
