#include <iostream>
int main() {
	int size;
	std::cout << "Square size" << std::endl;
	std::cin >> size;
	for(int row = size; row >= 1; row--){
		if (row == size || row == 1) {
			for (int i = size; i > 0; i--) {
				std::cout << "*";
			}
			std::cout << std::endl;
		}
		else {
			for (int i = size; i > 0; i--) {
				if (i == size) {
					std::cout << "*";
			}
				else if (i == 1) {
					std::cout << "*" << std::endl;
				}
				else {
					std::cout << " ";
				}
			}
		}
	}
}
