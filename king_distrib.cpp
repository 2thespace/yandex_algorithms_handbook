#include <iostream>
#include <cmath>

int calculateKings(int r, int c) {
    // Считаем количество:
    int maxKings = (std::ceil(r / 2.0) * std::ceil(c / 2.0)) + (std::floor(r / 2.0) * std::floor(c / 2.0));
    return maxKings;
}

int main() {
    int r, c;

    std::cin >> r;
    std::cin >> c;

    int result = calculateKings(r, c);
    std::cout  << r*c-std::ceil(r/3.0)*std::ceil(c/3.0) << std::endl;
    
    return 0;
}