#include <iostream>
#include "Array.h"

Array::Array(int dim, int* array_size) :dim(dim) {
	size = new int[dim];

	for (int i = 0; i < dim; i++) {
		size[i] = array_size[i];
	}

	top = new Address;
	top->level = 0;

	initialize_address(top);
}

Array::Array(const Array& arr) : dim(arr.dim)
{
	size = new int[dim];

	for (int i = 0; i < dim; i++) {
		size[i] = arr.size[i];
	}

	top = new Address;
	top->level = 0;

	initialize_address(top);
}

Array::~Array()
{
	delete_address(top);

	if (size) delete[] size;
}

void Array::initialize_address(Address* current)
{
	if (!current) return;

	// 종료 조건
	if (current->level == dim - 1) {
		current->next = new int[size[current->level]];
		return;
	}

	current->next = new Address[size[current->level]];

	// 다음 단계의 요소 정보 초기화
	for (int i = 0; i != size[current->level]; i++) {
		(static_cast<Address*>(current->next) + i)->level = current->level + 1;

		initialize_address(static_cast<Address*>(current->next) + i);
	}
}

void Array::delete_address(Address* current)
{
	if (!current) return;

	for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
		delete_address(static_cast<Address*>(current->next) + i);
	}

	delete[] current->next;
}

Array::Iterator::Iterator(Array* arr, int* loc /*= NULL*/) :arr(arr) {
	location = new int[arr->dim];

	for (int i = 0; i != arr->dim; i++) {
		location[i] = (loc != NULL) ? loc[i] : 0;
	}
}

Array::Iterator::Iterator(const Iterator& itr) :arr(itr.arr) {
	location = new int[arr->dim];

	for (int i = 0; i != arr->dim; i++) {
		location[i] = itr.location[i];
	}
}

Array::Iterator& Array::Iterator::operator++() {
	if (location[0] >= arr->size[0]) return *this;

	bool carry = false;
	int i = arr->dim - 1;

	do {
		location[i]++;

		if (location[i] >= arr->size[i] && i >= 1) {
			location[i] -= arr->size[i];
			carry = true;
			i--;
		}
		else {
			carry = false;
		}
	} while (i >= 0 && carry);

	return *this;
}

Array::Iterator Array::Iterator::operator++(int) {
	Iterator itr(*this);
	++(*this);

	return itr;
}

bool Array::Iterator::operator!=(const Iterator& itr) {
	if (itr.arr->dim != arr->dim) return true;

	for (int i = 0; i != arr->dim; i++) {
		if (itr.location[i] != location[i]) return true;
	}

	return false;
}

Array::Iterator Array::begin() {
	int* arr = new int[dim];

	for (int i = 0; i != dim; i++) {
		arr[i] = 0;
	}

	Iterator temp(this, arr);

	delete[] arr;

	return temp;
}

Array::Iterator Array::end() {
	int* arr = new int[dim];
	arr[0] = size[0];

	for (int i = 1; i < dim; i++) {
		arr[i] = 0;
	}

	Iterator temp(this, arr);

	delete[] arr;

	return temp;
}

Int Array::operator[](const int index)
{
	return Int(index, 1, static_cast<void*>(top), this);
}

Int Array::Iterator::operator*()
{
	Int start = arr->operator[](location[0]);

	for (int i = 1; i <= arr->dim - 1; i++) {
		start = start.operator[](location[i]);
	}

	return start;
}

Int::Int(int index, int _level /*= 0*/, void* _data /*= NULL*/, Array* _array /*= NULL*/) :
	level(_level),
	data(_data),
	array(_array)
{
	if (_level < 1 || index >= array->size[_level - 1]) {
		data = NULL;
		return;
	}

	if (level == array->dim) {
		data = static_cast<void*>(static_cast<int*>(static_cast<Array::Address*>(data)->next) + index);
	}
	else {
		data = static_cast<void*>(static_cast<Array::Address*>(static_cast<Array::Address*>(data)->next) + index);
	}
}

Int::operator int()
{
	if (data) return *static_cast<int*>(data);
	return 0;
}

Int& Int::operator=(const int& a)
{
	if (data) *static_cast<int*>(data) = a;
	return *this;
}

Int Int::operator[](const int index)
{
	if (!data) return 0;
	return Int(index, level + 1, data, array);
}