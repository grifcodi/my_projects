#include<iostream>

void build_triangle(int n) {
	int** triangle = new int*[n];

	for (int i = 0; i < n; i++) {
		triangle[i] = new int[n];
	}

	triangle[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) triangle[i][j] = 1;
			else triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
			std::cout << triangle[i][j] << " ";
		}
		std::cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] triangle[i];
	}
	delete[] triangle;
}

int main() {
	while(1) {
		int n;
		std::cout << "Enter n:";
		std::cin >> n;
		build_triangle(n);
	}
	return 0;
}
