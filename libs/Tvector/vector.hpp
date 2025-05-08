#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>

template<typename T>
struct vector 
{
	T* data;
	int size, capacity;

	vector(): size(0), capacity (8) {
		data = new T[capacity];
	}

	vector(int sized): size(sized), capacity(8) 
	{
		while (capacity < size) capacity *= 2;
		data = new T[capacity];
	}
	
	~vector() 
	{
		delete[] data;
	}

	void clear() 
	{
		delete[] data;
		size = 0;
		capacity = 8;
		data = new T[capacity];
	}

	void resize() 
	{
		capacity *= 2;
		T* new_data = new T[capacity];
		for (int i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
	}

	int get_size()
	{
		return size;
	}

	void print_size()
	{
		std::cout << "size: " << size << '\n';
	}

	int get_capacity()
	{
		return capacity;
	}

	void print_capacity()
	{
		std::cout << "capacity: " << capacity << '\n';
	}

	void push_back(const T n) 
	{
		if (size == capacity) 
		{
			resize();
		}
		data[size] = n;
		size++;
	}

	void pop_back() 
	{
		if (size == 0) 
		{
			std::cout << "Pop: vector is empty" << '\n';
			return;
		}
		size--;
	}
	
	void insert(const int index, const T value) 
	{
		if (index < 0 || index > size)
		{
			std::cout << "Insert: index out of bounds" << '\n';
			return;
		}

		if (size == capacity) 
		{
			resize();
		}

		for (int i = size; i > index; i--) 
		{
			data[i] = data[i-1];
		}
		
		data[index] = value;
		size++;
	}

	void pop_index(const int index) 
	{
		if (index < 0 || index > size)
                {
			std::cout << "Pop_index: index out of bounds" << '\n';
			return;
                }
			
		for (int i = index; i < size; i++) 
		{
			data[i] = data[i+1];
		}
		size++;
		data[size] = T();
	}

	void print_index(const int index)
	{
		if (index < 0 || index > size)
                {
                	std::cout << "Print_index: index out of bounds" << '\n';
			return;
		}
		std::cout << data[index];
		std::cout << '\n';
	}

	void print_vector() 
	{
		if (size == 0)
                {
                	std::cout << "Print_vector: vector is empty" << '\n';
			return;
		}
		for (int i = 0; i < size; i++) 
		{
			std::cout << data[i] << " ";
		}
		std::cout << '\n';
	}

};

#endif
