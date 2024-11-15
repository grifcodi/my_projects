/* Напишіть програму, яка читає 2 цілі числа a і b від користувача, а потім
друкує на екрані їхні:
- суму
- різницю
- добуток */

#include <iostream>
int main() {
	std::cout << "Enter a and b" << std::endl;
	int a, b;
	std::cin >> a >> b;
	std::cout << std::endl;
	std::cout << a+b << std::endl << a-b << std::endl << a*b << std::endl;
}
