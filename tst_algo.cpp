#include <iostream>


std::size_t factorial(std::size_t input_number, std::size_t start = 1) {
    std::size_t permutation = 1;
    for(auto i = start; i <= input_number; ++i) {
        permutation *= i;
    }
    return permutation;
}

std::size_t combinations(std::size_t k, std::size_t n) {
    if(n < k) return 0;
    auto n_f = factorial(n, k+1);

    auto n_k_f = factorial(n-k);

    return n_f/n_k_f;

}

std::size_t combinations_with_repeat(std::size_t k, std::size_t n) {
    return combinations(k, n + k - 1);
}

int main(void)
{
    std::size_t first, second;
    std::cin >> first >> second;

    std::cout << combinations_with_repeat(second, first) << std::endl;
}