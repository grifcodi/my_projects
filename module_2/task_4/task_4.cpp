/* Напишіть програму, яка має два параметри:
- перший параметр - один із варіантів:
1 – переведення одиниць за Цельсієм у Фаренгейт,
2 – переведення одиниць Фаренгейта в Цельсій,
- другий параметр - дійсне число, що виражає температуру.
Залежно від першого параметра програма перетворює температуру,
наведену в другому параметрі, між Фаренгейтом і Цельсієм. Після
перетворення програма виводить на екран розраховане значення з
точністю до двох знаків після коми.
Програма має бути стійкою до значень, менших за абсолютний нуль,
друкуючи повідомлення «Занадто холодно для підрахунку!». */

#include <iostream>
int main() {
	int a;
	std::cout << "Choose desired converter: " << std::endl;
	std::cout << "1 – Celsius to Fahrenheit" << std::endl;
	std::cout << "2 – Fahrenheit to Celsius" << std::endl;
	std::cin >> a;
	if (a != 1 && a != 2) {
		std::cout << "Invalid input: enter 1 or 2" << std::endl;
	}
	else {
		float temp;
		std::cout << "Enter the temperature: " << std::endl;
		std::cin >> temp;
		if (a == 1 && temp < -273.15) {
			std::cout << "Invalid input: cannot calculate values lower than absolute zero" << std::endl;
		}
		else if (a == 2 && temp < -460) {
		        std::cout << "Invalid input: cannot calculate values lower than absolute zero" << std::endl;
		}
		else if (a == 1) {
			std::cout << ((temp*9/5)+32) << std::endl;
		}
		else if (a == 2) {
			std::cout << ((temp-32)*5/9) << std::endl;
		}
	}
}
