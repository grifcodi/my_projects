/* Напишіть програму, яка:
- друкує таке повідомлення на екрані: "Enter the name: ",
- вчитує ім'я користувача з клавіатури,
- друкує на екрані повідомлення: "Hello...!" і виводить ім’я. */

#include <iostream>
#include <string>
int main() {
	std::cout << "Enter the name: " << std::endl;
	std::string name;
	std::cin >> name;
	std::cout << "Hello " << name << "!" << std::endl;
}
