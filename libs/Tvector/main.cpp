#include <iostream>
#include "vector.hpp"

int main() 
{
	vector<int> v;
	vector<char> ch;
	v.push_back(5);
	v.print_vector();
	v.print_size();
	v.print_capacity();
	ch.print_size();
	ch.print_capacity();
	ch.push_back('h');
	ch.push_back('e');
	ch.push_back('y');
	ch.print_size();
	ch.print_vector();
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			v.push_back(j+1);
			v.print_size();
		}
		v.pop_back();
	}
	v.insert(5, 7);
	v.print_index(5);
	v.print_index(6);
	v.pop_index(6);
	v.print_index(6);
	v.print_vector();
	v.print_size();
	v.print_capacity();
	v.push_back(111);
	v.print_vector();
	v.pop_back();
	v.print_vector();
	v.size = v.size+2;
	v.print_size();
	v.print_vector();
	std::cout<< '\n';
	return 0;
}
