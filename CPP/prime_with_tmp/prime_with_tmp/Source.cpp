#include <iostream>

template <int num>
class INT {
public:
    static const int num_ = num;
};

template <typename num1, typename num2>
class Add {
public:
    using result = INT<num1::num_ + num2::num_>;
};

template <typename num1, typename num2>
class Divide {
public:
    using result = INT<num1::num_ / num2::num_>;
};

using one = INT<1>;
using two = INT<2>;

template <typename num, typename div>
class CheckDiv {
public:
    static const bool result = 
        (num::num_ % div::num_ == 0) || CheckDiv<num, typename Add<div, one>::result>::result;
};


template <typename num>
class _IsPrime {
public:
    static const bool result = !CheckDiv<num, two>::result;
};

template <>
class _IsPrime <two> {
public:
    static const bool result = true;
};

template <typename num>
class CheckDiv<num, typename Divide<num, two>::result> {
public:
    static const bool result = num::num_ % (num::num_/2);
};

template <int num>
class IsPrime {
public:
    static const bool result = _IsPrime<INT<num>>::result;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << "2 : " << IsPrime<2>::result << std::endl;
    std::cout << "101 : " << IsPrime<101>::result << std::endl;
    std::cout << "299 : " << IsPrime<299>::result << std::endl;
    std::cout << "13 : " << IsPrime<13>::result << std::endl;

    return 0;
}