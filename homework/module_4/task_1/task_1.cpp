#include<iostream>

int powsq(int a) {
	return a*a;
}

void check_for_combinations(int n) {
	for (int c = 0; c < n; c++) {
		for (int a = 0; a < c; a++) {
			for (int b = 0; b < a; b++) {
				if (powsq(a) + powsq(b) == powsq(c)) {
					std::cout << "a: " << a << "; b: " << b << "; c: " << c << '\n';
				}
			}
		}
	}
}


int main() {
	while(1) {
		int n;
		std::cout << "Enter n: ";
		std::cin >> n;
		check_for_combinations(n);
	}
	return 0;
}
