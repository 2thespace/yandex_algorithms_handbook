#include <iostream>
#include <cstdint>

uint64_t Fibbo(int number) {
    if(number <= 0) return 0;
    if(number == 1) return 1;
    uint64_t prev1 = 0;
    uint64_t prev2 = 1;
    uint64_t Fibbo;
    for(auto i = 2; i <= number; ++i) {
        Fibbo = prev1 + prev2;
        prev1 = prev2;
        prev2 = Fibbo;
    }
    return Fibbo;
}

uint64_t FindFibbo(int number) {
    uint64_t return_fibo = 0;
    uint64_t count_number = number < 10 ? 10 + number : number;
    for(auto i =0; i <= count_number; ++i) {
        auto fibbo = Fibbo(i);
        if(fibbo <= number) {
            return_fibo = i;
        }
        else
            break;
    }
    return  return_fibo;
}

int main(int argc, char **argv) {

    int n;
    std::cin >> n;
    auto k = FindFibbo(n);
    std::cout << Fibbo(k-1) << " " << Fibbo(k) << std::endl;
    return 0;
}