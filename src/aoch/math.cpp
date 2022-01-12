#include "aoch/math.hpp"

namespace aoch {

template <>
sum_type<bool>::type sum<bool>(
    const std::vector<bool>& in,
    typename sum_type<bool>::type initial_value
) {
    typename sum_type<bool>::type sum = initial_value;

    for (typename std::vector<bool>::size_type i = 0; i < in.size(); ++i)
        sum += in[i];

    return sum;
}

} // namespace aoch
