#include <iostream>

const char* first_digit[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
const char* teens_digit[] = {"ten", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
const char* second_digit[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char* third_digit[] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ", "six hundred ", "seven hundred ", "eight hundred ", "nine hundred "};
const char fourth_digit[] = {"one thousand "};


void num_word(int n) 
{
	if (n == 0) 
	{
		std::cout << "zero";
	}
	if (n == 1000) 
	{
		std::cout << fourth_digit;
		n %= 1000;
	}
	if (n <= 999 && n >= 100) 
	{
		std::cout << third_digit[n/100];
		n %= 100;
	}
	if (n <= 99 && n >= 20) 
	{
		std::cout << second_digit[n/10];
		n %= 10;
	}
	if (n <= 19 && n >= 10) 
	{
		std::cout << teens_digit[n%10];
	}
	if (n <= 9 && n >= 1) 
	{
		std::cout << first_digit[n];
	}	
}

int main() 
{
	while(1) 
	{
		int n;
		std::cout << "Enter n:";
		std::cin >> n;
		num_word(n);
		std::cout << '\n';
	}
}
