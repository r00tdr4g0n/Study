#include "Number.h"

Number::Number(int n = 0) :num(n)
{
	std::cout << "Number(int n=0)" << std::endl;
}

Number& Number::operator=(const Number& ref)
{
	std::cout << "operator=()" << std::endl;
	num = ref.num;

	return *this;
}

Number::operator int()
{
	return num;
}

void Number::ShowNumber()
{
	std::cout << num << std::endl;
}