#pragma once

class MyString {
private:
	char* string_content;
	int string_length;
	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);

	int length() const;

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	int capacity() const;
	void reserve(int size);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);

	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;

	~MyString();
};