#include <iostream>
#include "Complex.h"

Complex::Complex(const char* str)
{
	int begin = 0, end = strlen(str);
	int pos_i = -1;

	img = 0.0;
	real = 0.0;

	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;

			break;
		}
	}

	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);

		return;
	}

	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const Complex& c) 
{
	Complex temp(real + c.real, img + c.img);

	return temp;
}

Complex Complex::operator-(const Complex& c)
{
	Complex temp(real - c.real, img - c.img);

	return temp;
}

Complex Complex::operator*(const Complex& c)
{
	Complex temp(real * c.real - img * c.img, real * c.img + c.real * img);

	return temp;
}

Complex Complex::operator/(const Complex& c)
{
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
	);

	return temp;
}

Complex Complex::operator+(const char* str)
{
	Complex temp(str);

	return (*this) + temp;
}

Complex Complex::operator-(const char* str)
{
	Complex temp(str);

	return (*this) - temp;
}

Complex Complex::operator*(const char* str)
{
	Complex temp(str);

	return (*this) * temp;
}

Complex Complex::operator/(const char* str)
{
	Complex temp(str);

	return (*this) / temp;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;

	return *this;
}

Complex& Complex::operator+=(const Complex& c)
{
	*this = *this + c;

	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	*this = *this - c;

	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	*this = *this * c;

	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	*this = *this / c;

	return *this;
}

double Complex::get_number(const char* str, int from, int to) 
{
	bool minus = false;
	bool integer_part = true;
	double num = 0.0;
	double decimal = 1.0;

	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.') {
			integer_part = false;
		}
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else {
			break;
		}
	}

	if (minus) num *= -1.0;

	return num;
}

// �����Ϸ��� Complex(const char* str) �����ڸ� ã�Ƽ� �Ͻ��� ��ȯ (implicit)
Complex operator+(const Complex& a, const Complex& b)
{
	Complex temp(a.real + b.real , a.img + b.img);

	return temp;
}

