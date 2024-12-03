#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int a = 1, b = 1;
	for (int i = 0; i < n; i++) {
		if (i <= 1) {
			std::cout << "1 ";	
		}
		else if (i%2 == 0) {
			std::cout << a+b << " ";
			a += b;
		}
		else {
			std::cout << a+b << " ";
			b += a;
		}
	}
	std::cout << std::endl;
}
