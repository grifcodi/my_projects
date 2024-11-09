#include <iostream>
int main() {
	int arr[6]={1, 2, 3, 4, 5, 6};
	for(int arrcount=5; arrcount > -1; arrcount--) {
		std::cout << arr[arrcount] << " ";
	}
	std::cout << std::endl  << "hello world" << std::endl;
}
