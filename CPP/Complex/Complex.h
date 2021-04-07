#pragma once

#include <iostream>

// z = a + bi
// 실수부와 허수부

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

	// 전역함수 operator+ 가 Complex 클래스의 모든 요소에 접근 가능
	friend Complex operator+(const Complex& a, const Complex& b);

	void println()
	{
		std::cout << " ( " << real << ", " << img << " ) " << std::endl;
	}
};