#pragma once
#include <iostream>

class Vector {
private:
	std::string* m_data;
	int m_capacity;
	int m_length;

public:
	Vector(int num = 1);
	void PushBack(std::string character);
	std::string operator[](int i);
	void Remove(int pos);
	int Size();
	~Vector();
};