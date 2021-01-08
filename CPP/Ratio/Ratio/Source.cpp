#include <iostream>
#include "ratio.h"

int main()
{
	using ratio1 = Ratio<3, 2>;
	using ratio2 = Ratio<2, 3>;
	using add_result = AddResult<ratio1, ratio2>;
	using sub_result = SubResult<ratio1, ratio2>;
	using mul_result = MulResult<ratio1, ratio2>;
	using div_result = DivResult<ratio1, ratio2>;

	std::cout << add_result::num_ << " / " << add_result::den_ << std::endl;
	std::cout << sub_result::num_ << " / " << sub_result::den_ << std::endl;
	std::cout << mul_result::num_ << " / " << mul_result::den_ << std::endl;
	std::cout << div_result::num_ << " / " << div_result::den_ << std::endl;

	return 0;
}