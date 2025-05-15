#include <iostream>
#include <fstream>
#include "../../../libs/Tvector/vector.hpp"



int main() 
{
	char filename[100];
	std::cout << "Enter the path of the .txt file: ";
	std::getline(filename, 100);
	std::ifstream file(filename);

	while (file.getline(buffer,
}

