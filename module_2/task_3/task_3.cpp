/* Напишіть програму, яка перевірятиме, чи є задане ціле число в
десятковій системі парним числом і чи ділиться воно на 8 і 16.
Програма виводить подільність зі словами «ТАК» і «НІ» та виводить
задане число у вісімковому форматі. і шістнадцятковій формі. */

#include <iomanip>
#include <iostream>
int main() {
	int a;
	std::cout << "Enter a: " << std::endl;
	std::cin >> a;
	std::cout << std::endl << "Even number: ";
	if (a%2 == 0) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	std::cout << "Devisible by 8: ";
	if (a%8 == 0) {
	        std::cout << "Yes" << std::endl;
        }
        else {
                std::cout << "No" << std::endl;
        }  
	std::cout << "Devisible by 16: ";
        if (a%16 == 0) {
                std::cout << "Yes" << std::endl;
        }
        else {
                std::cout << "No" << std::endl;
        }
	std::cout << "8-base: " << std::oct << a << std::endl;
	std::cout << "16-base: " << std::hex << a << std::endl;
}
