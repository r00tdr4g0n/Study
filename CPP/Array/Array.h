#pragma once

#include <iostream>

class Int;

class Array {
	friend Int;

private:
	const int dim;
	int* size;

	struct Address {
		int level;
		void* next;
	};

	Address* top;

public:
	Array(int dim, int* array_size);
	Array(const Array& arr);
	~Array();
	void initialize_address(Address* current);
	void delete_address(Address* current);
	Int operator[](const int index);

	class Iterator {
	private:
		int* location;
		Array* arr;

	public:
		Iterator(Array* arr, int* loc = NULL);
		Iterator(const Iterator& itr);

		/*~Iterator() {
			if (location) {
				delete[] location;
			}
		}*/

		Iterator& operator++();
		Iterator operator++(int);
		bool operator!=(const Iterator& itr);
		Int operator*();
	};

	Iterator begin();
	Iterator end();
};

class Int {
private:
	void* data;
	int level;
	Array* array;

public:
	Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL);
	Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}
	operator int();
	Int& operator=(const int& a);
	Int operator[](const int index);
};