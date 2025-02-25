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
		if (index >= 0 && index < size) {
			array[index] = value;
		}
	}

	void push_back (int value) {
		if (size >= capacity) {
			capacity *= 2;
			int* new_array = new int[capacity];

			for (int i = 0; i < size; i++) {
				new_array[i] = array[i];
			}

			delete[] array;
			array = new_array;
		}

		array[size] = value;
		size++;	
	}

	int get_value (int index) {
		if (index >= 0 && index < size) {
		return array[index];
		}
		else {
			return -1;
		}
	}

	int get_size () {
		return size;
	}

	~vector() {
		std::cout << "destructor" << '\n';
		delete[] array;
	}
};

int main() {

	vector v(10);
	for (int i = 0; i < 15; i++)
	{
		v.push_back(i);
		std:: cout << v.get_value(i) << " " << v.get_size() << '\n';
	}
	return 0;
}

