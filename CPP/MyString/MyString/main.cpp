#include "mystring.h"

int main()
{
	MyString str1("Hello Hello Hello Hello Hello Hello Hello Hello Hello cpp");
	str1.reserve(100);

	cout << "Capacity : " << str1.capacity() << endl;
	cout << "String Length : " << str1.length() << endl;

	str1.println();

	return 0;
}