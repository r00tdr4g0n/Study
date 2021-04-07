#pragma once

#include <iostream>

// z = a + bi
// �Ǽ��ο� �����

class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to);

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real; img = c.img; }
	Complex(const char* str);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex operator+(const char* str);
	Complex operator-(const char* str);
	Complex operator*(const char* str);
	Complex operator/(const char* str);

	Complex& operator=(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	// �����Լ� operator+ �� Complex Ŭ������ ��� ��ҿ� ���� ����
	friend Complex operator+(const Complex& a, const Complex& b);

	void println()
	{
		std::cout << " ( " << real << ", " << img << " ) " << std::endl;
	}
};