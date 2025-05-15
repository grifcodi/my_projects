#include <iostream>

struct string
{
	char* data;
	int len, capacity;
	
	string(): len(0), capacity(8)
	{
		data = new char[capacity];
	}
	
	string(char* str): len(0), capacity(8)
	{
		while (str[len] != '\0') len++;
		while (capacity < len) capacity *= 2;
		data = new char[capacity];
		for (int i = 0; i < len; i++) data[i] = str[i];
		data[len] = '\0';
	}

	~string()
	{
		delete[] data;
	}

	void resize 
	{
		capacity *= 2;
		char* new_data = new char[capacity];
		for (int i = 0; i < len; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;

	int size()
	{
		return len;
	}
	void print_size()
	{
		std::cout << len;
	}

	void clear()
	{
		len = 0;
		capacity = 0;
		delete[] data;
		data = new char[capacity];
		data[0] = '\0';
	}
	
	char& operator[] (int index)
	{
		if (index < 0 || index >= len)
		{
			std::cout << "Index: " << index << " out of range" << '\n';
			return;
		}
			return data[index];
	}
	
	void push_back(char ch)
	{
		if (len == capacity) resize();
		data[len++] = ch;
		data[len] = '\0';
	}

	void pop_back()
	{
		if (0 == size)
		{
			std::cout << "Pop: string is empty" << '\n';
			return;
		}
		len--;
		data[len] = '\0';
	}

