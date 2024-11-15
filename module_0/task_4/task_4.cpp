/* Напишіть програму для обчислення площі поверхні та об’єму
паралелепіпеда з розмірами заданих вимірів A, B і C. */

#include <iostream>
int main() {
	std::cout << "Enter A, B, C" << std::endl;
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << 2*(a*b+b*c+c*a) << " " << (a*b*c) << std::endl;
}
