#include <iostream>

unsigned long int factorial(unsigned int);

int main() {
	unsigned int n;
	std::cin >> n;
	unsigned long int r = factorial(n);
	std::cout << r << std::endl;
	return 0;
}

unsigned long int factorial (unsigned int n) {
	unsigned long int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

