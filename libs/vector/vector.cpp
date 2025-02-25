#include<iostream>

struct vector {
	int size;
	int capacity;
	int* array;

	vector (int size):capacity(size*2) {
		array = new int[capacity];
		this->size = size;
		std::cout << "constructor" << '\n';
	}

	void set_value (int value, int index) {
		array[index] = value;
	}

//	void push_back (const value_type&, value) {
//		if () {
//
//		}
//		else {
//
//		}	
//	}

	int get_value (int index) {
		return array[index];
	}

	int get_size () {
		return size;
	}

	~vector() {
		std::cout << "deconsructor" << '\n';
		delete[] array;
	}
};

int main() {

	vector v(10);
	for (int i = 0; i < 50; i++)
	{
		v.set_value(i, i);
		v.get_value(i);
		v.get_size;
	}
}

