/* Напишіть програму, яка завантажує два числа з вибраною точністю, а
потім обчислює та друкує результати (сума, різниця, добуток і частка) з
точністю до 12 знаків після коми. */

#include <iomanip>
#include <iostream> 
int main() {
	std::cout << "Enter a and b" << std::endl;
	double a, b;
	std::cin >> a >> b;
	std::cout << std::setprecision(12) << std::endl; 
	std::cout << a+b << std::endl << a-b << std::endl << a*b << std::endl << a/b << std::endl;
}
