#include<iostream>
#include"../task_3/task_3_sieve.cpp"

void breakdown(int n) {
	
	int ammount;
	int* comp_arr = sieve(n, ammount);
	
	for (int i = 0; i < ammount; i++) {
		while (n % comp_arr[i] == 0) {
			std::cout << comp_arr[i] << " ";
			n /= comp_arr[i];
		}
		if (n == comp_arr[i]) {
			std::cout << comp_arr[i] << '\n';
			break;
		}
	}
	delete[] comp_arr;
}

int main() {
	while(1) {
		int n;
		std::cout << "Enter n:";
		std::cin >> n;
		breakdown(n);
	}
	return 0;
}
