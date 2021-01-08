#pragma once
#include <iostream>

using namespace std;

class MyString
{
private:
	char* m_stringContent;
	int m_stringLength;
	int m_memoryCapacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
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
	int find(int findFrom, MyString& str) const;
	int find(int findFrom, char* str) const;
	int find(int findFrom, char c) const;
	int compare(const MyString& str) const;
};