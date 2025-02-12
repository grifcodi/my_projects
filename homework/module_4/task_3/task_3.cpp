#include<iostream>
#include"task_3_sieve.cpp"

int* sieve (int n, int& ammount);

int main () {
	while(1) {
		int n;
		std::cout << "Enter n:";
		std::cin >> n;
		int ammount;
		int* comp_arr = sieve(n, ammount);
	
		for (int i = 0; i < ammount; i++) {
			std::cout << comp_arr[i] << " ";
		}
		std::cout << '\n';

		delete[] comp_arr;
	}
	return 0;
}


