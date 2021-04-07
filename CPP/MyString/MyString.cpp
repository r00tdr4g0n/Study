#include "MyString.h"
#include <iostream>

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	string_content = new char[string_length];
	memory_capacity = string_length;

	memcpy(string_content, str, string_length);
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	string_content = new char[string_length];
	memory_capacity = str.string_length;

	memcpy(string_content, str.string_content, string_length);
}

int MyString::length() const
{
	return string_length;
}

void MyString::print() const
{
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const
{
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}

	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) 
{
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	memcpy(string_content, str.string_content, str.string_length);

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) 
{
	int str_length = strlen(str);

	if (str_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	memcpy(string_content, str, str_length);

	string_length = str_length;

	return *this;
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity) {
		char* prev_string_constent = string_content;

		string_content = new char[size];
		memory_capacity = size;

		memcpy(string_content, prev_string_constent, string_length);

		delete[] prev_string_constent;
	}
}

char MyString::at(int i) const 
{
	if (i >= string_length || i < 0) {
		return NULL;
	}
	else {
		return string_content[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {

		if (memory_capacity * 2 > string_length + str.string_length) {
			memory_capacity *= 2;
		}
		else {
			memory_capacity = string_length + str.string_length;
		}
		
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		memcpy(string_content, prev_string_content, loc);
		memcpy(&string_content[loc], str.string_content, str.string_length);
		memcpy(&string_content[loc+str.string_length], &prev_string_content[loc], string_length-loc);

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		
		return *this;
	}

	memcpy(&string_content[loc+str.string_length], &string_content[loc], string_length-loc);
	memcpy(&string_content[loc], str.string_content, str.string_length);

	string_length = string_length + str.string_length;

	return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > string_length) return *this;

	memcpy(&string_content[loc], &string_content[loc+num], string_length-loc-num);

	string_length -= num;

	return *this;
}

int MyString::find(int find_from, MyString& str) const
{
	int i, j;

	if (str.string_length == 0) return -1;

	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1;
}

int MyString::find(int find_from, const char* str) const
{
	MyString temp(str);

	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const
{
	MyString temp(c);

	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const
{
	int result = memcmp(this->string_content, str.string_content, std::min(string_length, str.string_length));

	if (string_length != str.string_length) {
		if (result) {
			return result;
		}
		else {
			return string_length > str.string_length ? 1 : -1;
		}
	}
	else {
		return result;
	}
}

bool MyString::operator==(MyString& str)
{
	return !compare(str);
}

char& MyString::operator[](const int index)
{
	return string_content[index];
}

MyString::~MyString()
{
	if (string_content) delete[] string_content;
}