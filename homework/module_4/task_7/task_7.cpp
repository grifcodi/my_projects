#include <iostream>
#include "../task_3/task_3_sieve.cpp"

void prime_diff(int n)
{
	int ammount;
	int* complete_arr = sieve(n*2, ammount);
	
	for (int i = ammount-1; complete_arr[i] > n; i--) 
	{
		for (int j = i; complete_arr[j] > n; j--) 
		{
			if (complete_arr[i] - complete_arr[j] == 2)
			{
				std::cout << "Found pair: " << complete_arr[i] << "-" << complete_arr[j] << "=2" << "\n";
			}
		}
	}
}

int main() 
{
	while(1)
	{
		int n;
		std::cout << "Enter n: ";
		std::cin >> n;
		prime_diff(n);
	}
}
