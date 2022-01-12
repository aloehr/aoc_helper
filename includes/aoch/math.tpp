namespace aoch {

template <typename T>
typename sum_type<T>::type sum(
    const std::vector<T>& in,
    typename sum_type<T>::type initial_value
) {
    typename sum_type<T>::type sum = initial_value;

    for (typename std::vector<T>::size_type i = 0; i < in.size(); ++i)
        sum += in[i];

    return sum;
}

} // namespace aoch
