#pragma once

#include <vector>


namespace aoch {

template <typename T>
struct sum_type { typedef T type; };

template <>
struct sum_type<bool> { typedef unsigned int type; };

template <typename T>
typename sum_type<T>::type sum(
    const std::vector<T>& in,
    typename sum_type<T>::type initial_value = typename sum_type<T>::type()
);

template <>
sum_type<bool>::type sum<bool>(
    const std::vector<bool>& in,
    typename sum_type<bool>::type initial_value
);

} // namespace aoch

#include "math.tpp"
