#include "Vector.h"

Vector::Vector(int num) :
	m_data(new std::string[num]),
	m_capacity(num),
	m_length(0)
{}

void Vector::PushBack(std::string character)
{
	if (m_capacity <= m_length) {
		std::string* temp = new std::string[m_capacity * 2];

		for (int i = 0; i < m_length; i++) {
			temp[i] = m_data[i];
		}

		delete[] m_data;
		m_data = temp;
		m_capacity *= 2;
	}

	m_data[m_length] = character;
	m_length++;
}

std::string Vector::operator[](int i)
{
	return m_data[i];
}

void Vector::Remove(int pos)
{
	for (int i = pos + 1; i < m_length; i++) {
		m_data[i - 1] = m_data[i];
	}
	m_length--;
}

int Vector::Size()
{
	return m_length;
}

Vector::~Vector()
{
	if (m_data) {
		delete[] m_data;
	}
}