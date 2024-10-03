#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <unordered_map>

 #define ENABLE_TEST

template<typename T>
bool find_dom_el(std::vector<T> const& v) {
    auto candidate = 0;
    auto sign = 0;
    T elem{};
    for(auto i = 0; i < v.size(); ++i) {
        
        if(!candidate) {
            elem = v[i];
            candidate++;
        }
        else if(elem == v[i]) {
           candidate++;
        } else {
            candidate--;
        }
    }
    return candidate;
}

template<typename T>
bool find_dom_el4(std::vector<T> const& v) {
    std::unordered_map<T,int> counter;
    for(auto& el:v) {
        counter[el]++;
    }
    auto n = v.size()/4;
    auto el_count = 0;
    for(auto& [key, count] : counter) {
        if(count > n) {
            el_count++;
        }
    }
    return el_count == 3? true: false;
}



void Test() {
/*
5
2 3 9 2 2

1
*/
#ifdef ENABLE_TEST

#endif
}

int main(int argc, char** argv) {
    using my_type = int;
    int n;
    std::cin >> n;
    std::vector<my_type> elems;
    elems.reserve(n);
    while(n--) {
        my_type el;
        std::cin >> el;
        elems.push_back(el);
    }
    std::cout << find_dom_el4(elems) << std::endl;
    return 0;
}