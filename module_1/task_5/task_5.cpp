/* Напишіть програму для обчислення площі круга та довжини кола із
заданим радіусом R. Прийміть значення pi = 3,14. Перерахуйте
отримані значення з точністю до 2 знаків після коми. */

#include <iostream>
int main () {
	std::cout << "Enter R" << std::endl;
	float r, p = 3.14;
	std::cin >> r;
	float a = p*r*r;
	float b = 2*p*r;
	std::cout << a << " " << b << std::endl;
}
