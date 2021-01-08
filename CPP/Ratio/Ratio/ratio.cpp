#pragma once
template<int num1, int num2>
class Gcd {
public:
	static const int val_ = Gcd<num2, num1% num2>::val_;
};

template <int num>
class Gcd<num, 0> {
public:
	static const int val_ = num;
};

template <int num, int den = 1>
class Ratio {
private:
	const static int gcd_ = Gcd<num, den>::val_;

public:
	// 자기 자신을 가리키는 타입
	using type = Ratio<num / gcd_, den / gcd_>;
	static const int num_ = num / gcd_;
	static const int den_ = den / gcd_;
};

template <class Ratio1, class Ratio2>
class AddRatio {
public:
	using type = Ratio<Ratio1::num_* Ratio2::den_ + Ratio2::num_ * Ratio1::den_, Ratio1::den_* Ratio2::den_>;
};

template <class Ratio1, class Ratio2>
class SubRatio {
public:
	using type = Ratio<Ratio1::num_* Ratio2::den_ - Ratio2::num_ * Ratio1::den_, Ratio1::den_* Ratio2::den_>;
};

template <class Ratio1, class Ratio2>
class MulRatio {
public:
	using type = Ratio<Ratio1::num_* Ratio2::num_, Ratio1::den_* Ratio2::den_>;
};

template <class Ratio1, class Ratio2>
class DivRatio {
public:
	using type = Ratio<Ratio1::num_* Ratio2::den_, Ratio1::den_* Ratio2::num_>;
};

template <class R1, class R2>
class AddResult : public AddRatio<R1, R2>::type {};

template <class R1, class R2>
class SubResult : public SubRatio<R1, R2>::type {};

template <class R1, class R2>
class MulResult : public MulRatio<R1, R2>::type {};

template <class R1, class R2>
class DivResult : public DivRatio<R1, R2>::type {};
