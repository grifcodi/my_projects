/* Напишіть програму, яка завантажує символ у змінну char, а потім
друкує символ та його ASCII-код у десятковому та шістнадцятковому
форматі на екран. */

#include <iomanip>
#include <iostream>
int main() {
	char a;
	std::cout << "Enter var: " << std::endl;
	std::cin >> a;
	std::cout << "Variable: " << a << std::endl;
	std::cout << "ASCII 10-bit: " << int(a) << std::endl;
	std::cout << "ASCII 16-bit: " << std::hex << int(a) << std::endl;
}	
