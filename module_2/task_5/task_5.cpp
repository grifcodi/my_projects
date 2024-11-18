/* Напишіть програму, яка читає дійсне число з точністю до одного знака
після коми. Це число має бути в діапазоні 0,0...9,0 і виражати кількість
балів із тесту.
Програма, використовуючи умовний оператор if-else, видає (друкує на
екран) результат цих точок за такою схемою:
0,0 ... 4,4 – незадовільна оцінка (2,0),
4,5 ... 5,2 – задовільний (3,0),
5,3 ... 6,2 – оцінка вище задовільно (3,5),
6,3 ... 7,2 – хороша оцінка (4,0),

7,3 ... 8,2 – оцінка вище добре (4,5),
8,3 ... 9,0 – дуже добре (5,0)
В інших випадках відображається повідомлення «Неправильна
кількість пунктів!». */

#include <iomanip>
#include <iostream>
int main() {
	float a;
	std::cout << "Enter the grade: " << std::endl;
	std::cin >> a;
	if (a < 0 || a > 9) {
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	else if (a >= 0 && a <= 4.4) {
		std::cout << "Unsatisfactory grade (2,0)" << std::endl;
		return 0;
	}
	else if (a >= 4.5 && a <= 5.2) {
		std::cout << "Satifactory grade (3,0)" << std::endl;
		return 0;
	}
	else if (a >= 5.3 && a <= 6.2) {
		std::cout << "Above satisfactory grade (3,5)" << std::endl;
		return 0;
	}
	else if (a >= 6.3 && a <= 7.2) {
		std::cout << "Good grade (4,0)" << std::endl;
		return 0;
	}
	else if (a >= 7.3 && a <= 8.2) {
		std::cout << "Above good grade (4,5)" << std::endl;
		return 0;
	}
	else if (a >= 8.3 && a <= 9.0) {
		std::cout << "Very good (5,0)" << std::endl;
		return 0;
	}
}	
