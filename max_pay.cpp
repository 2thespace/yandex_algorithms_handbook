#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>
#include <cassert>
#include <cmath>

#define ENABLE_TEST

template<typename T>
bool IsBetter(T a, T b) {
    std::vector<T> a_digits;
    std::vector<T> b_digits;
    while(a !=0 || b !=0) {
        if(a !=0) {
            a_digits.push_back(a%10);
            a/=10;
        }
        if(b!=0) {
            b_digits.push_back(b%10);
            b/=10;
        }
    }
    std::ranges::reverse(a_digits);
    std::ranges::reverse(b_digits);
    T l{}, r{};
    for(auto i = 0; i != b_digits.size(); ++i) {
        l += b_digits[i]*std::pow(10, b_digits.size() - i - 1);
        r += b_digits[i]*std::pow(10, b_digits.size() - i - 1)*std::pow(10, a_digits.size());
    }
    for(auto i = 0; i != a_digits.size(); ++i) {
        r += a_digits[i]*std::pow(10, a_digits.size() - i - 1);
        l += a_digits[i]*std::pow(10, a_digits.size() - i - 1)*std::pow(10, b_digits.size()); 
    }
    return l > r;
    
    
}

template<typename T>
std::string LargesConcatenate(std::vector<T>& numbers) {

std::string concat{};
while(!numbers.empty()) {
    T max_number = numbers[0];
    int i = 0;
    int index = 0;
    for(auto& number:numbers) {
        if(IsBetter(number, max_number)) {
            max_number = number;
            index = i;
        }
        i++;
    }
    concat+= std::to_string(max_number);
    numbers.erase(numbers.begin() + index);
}
return concat;
}


void Test()
{
#ifdef ENABLE_TEST
    std::vector<int> v{21, 2};
    assert("221" == LargesConcatenate(v));
    v = {9,4,6,1,9};
    assert("99641" == LargesConcatenate(v));
    v = {23, 39,92};
    assert("923923" == LargesConcatenate(v));
#endif
}


int main(int argc, char ** argv) {
    Test();
    int n;
    std::cin >> n;
    std::vector<int> numbers;
    numbers.reserve(n);
    while(n--) {
        int number;
        std::cin >> number;
        numbers.push_back(number);
    }
    std::cout << LargesConcatenate(numbers) << std::endl;
    return 0;
}
