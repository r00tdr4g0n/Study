#include "mystring.h"

MyString::MyString(char c)
{
	m_stringContent = new char[1];
	m_stringContent[0] = c;
	m_stringLength = 1;
	m_memoryCapacity = 1;
}

MyString::MyString(const char* str)
{
	m_stringLength = strlen(str);
	m_memoryCapacity = m_stringLength;
	m_stringContent = new char[m_stringLength];

	for (int i = 0; i < m_stringLength; i++) m_stringContent[i] = str[i];
}

MyString::MyString(const MyString& str)
{
	m_stringLength = str.m_stringLength;
	m_memoryCapacity = str.m_stringLength;
	m_stringContent = new char[m_stringLength];

	for (int i = 0; i < m_stringLength; i++) m_stringContent[i] = str.m_stringContent[i];
}

MyString::~MyString()
{
	delete[] m_stringContent;
}

int MyString::length() const
{
	return m_stringLength;
}

void MyString::print() const
{
	for (int i = 0; i < m_stringLength; i++) cout << m_stringContent[i];
}

void MyString::println() const
{
	for (int i = 0; i < m_stringLength; i++) cout << m_stringContent[i];
	
	cout << endl;
}

MyString& MyString::assign(const MyString& str)
{
	if (str.m_stringLength > m_memoryCapacity) {
		delete[] m_stringContent;

		m_stringContent = new char[str.m_stringLength];
		m_memoryCapacity = str.m_stringLength;
	}

	for (int i = 0; i < str.m_stringLength; i++) m_stringContent[i] = str.m_stringContent[i];

	m_stringLength = str.m_stringLength;

	return *this;
}

MyString& MyString::assign(const char* str)
{
	int strLength = strlen(str);

	if (strLength > m_memoryCapacity) {
		delete[] m_stringContent;

		m_stringContent = new char[strLength];
		m_memoryCapacity = strLength;
	}

	for (int i = 0; i < strLength; i++)m_stringContent[i] = str[i];

	m_stringLength = strLength;

	return *this;
}

int MyString::capacity() const
{
	return m_memoryCapacity;
}

void MyString::reserve(int size)
{
	if (size > m_memoryCapacity) {
		char* prev_stringContent = m_stringContent;
		m_stringContent = new char[size];
		m_memoryCapacity = size;

		for (int i = 0; i < m_stringLength; i++) {
			m_stringContent[i] = prev_stringContent[i];
		}

		delete[] prev_stringContent;
	}
}

char MyString::at(int i) const
{
	if (i >= m_stringLength || i < 0) {
		return NULL;
	}
	else {
		return m_stringContent[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > m_stringLength) return *this;

	if (m_stringLength + str.m_stringLength > m_memoryCapacity) {
		if (m_memoryCapacity * 2 > m_stringLength + str.m_stringLength) {
			m_memoryCapacity *= 2;
		}
		else {
			m_memoryCapacity = m_stringLength + str.m_stringLength;
		}

		char* prev_stringContent = m_stringContent;
		m_stringContent = new char[m_memoryCapacity];

		int i;

		for (i = 0; i < loc; i++) {
			m_stringContent[i] = prev_stringContent[i];
		}

		for (int j = 0; j < str.m_stringLength; j++) {
			m_stringContent[i + j] = str.m_stringContent[j];
		}

		for (; i < m_stringLength; i++) {
			m_stringContent[str.m_stringLength + i] = prev_stringContent[i];
		}

		delete[] prev_stringContent;

		m_stringLength = m_stringLength + str.m_stringLength;

		return *this;
	}

	for (int i = m_stringLength - 1; i >= loc; i--) {
		m_stringContent[i + str.m_stringLength] = m_stringContent[i];
	}

	for (int i = 0; i < str.m_stringLength; i++) {
		m_stringContent[i + loc] = str.m_stringContent[i];
	}

	m_stringLength = m_stringLength + str.m_stringLength;

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
	if (num < 0 || loc < 0 || loc > m_stringLength || num > m_stringLength - loc) return *this;

	for (int i = loc + num; i < m_stringLength; i++) {
		m_stringContent[i - num] = m_stringContent[i];
	}

	m_stringLength -= num;

	return *this;
}

int MyString::find(int findFrom, MyString& str) const
{
	int i, j;

	if (str.m_stringLength == 0) return -1;

	for (i = findFrom; i <= m_stringLength - str.m_stringLength; i++) {
		for (j = 0; j < str.m_stringLength; j++) {
			if (m_stringContent[i + j] != str.m_stringContent[j]) break;
		}

		if (j == str.m_stringLength) return i;
	}

	return -1;
}

int MyString::compare(const MyString& str) const
{
	for (int i = 0; i < min(m_stringLength, str.m_stringLength); i++) {
		if (m_stringContent[i] > str.m_stringContent[i]) return 1;
		else if (m_stringContent[i] < str.m_stringContent[i]) return -1;
	}

	if (m_stringLength == str.m_stringLength) return 0;
	else if (m_stringLength > str.m_stringLength) return 1;

	return -1;
}