#include <iostream>
#include <typeinfo>

template <int N>
struct Int {
	static const int num = N;
	int m_num = N;
};

template <typename T, typename U>
struct add {
	typedef Int<T::num + U::num> result;
	//Int<T::num + U::num> result;
	result r;
};

struct test {
	int m_num = 10;
};

int main() {
	typedef Int<1> o;
	typedef Int<2> t;
	typedef add<o, t>::result r;

	struct Int<3> three;
	o one;
	struct Int<5> five;
	t two;
	struct add<o, t> a;
	struct test tt;

	std::cout << three.num << std::endl;
	std::cout << five.num << std::endl;
	std::cout << tt.m_num << std::endl;
	std::cout << one.num << std::endl;
	std::cout << two.num << std::endl;
	std::cout << "Addtion result : " << a.r.num << std::endl;

	return 0;
}