#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <unordered_map>

//  #define ENABLE_TEST


template<typename T>
int binary_search(std::vector<T> const& v, T elem) {
    int head = 0;   
    int tail = v.size() - 1;
    while(head <= tail) {
        auto mid =  (tail + head)/2;
        if(v[mid] == elem) {
            return mid;
        }
        if(v[mid] > elem) {
            tail =  mid -1;
        }
        else {
            head = mid + 1;
        }
    }
    return -1;
}



void Test(){
#ifdef ENABLE_TEST
    /*
    5 3
    2 3 9 11 20
    2

    5 2
    2 3 9 11 20
    9

    4 2
    1 2 1 2
    0
    */

#endif
}

int main(int argc, char ** argv) {
    using my_type = int;
    int n;
    std::cin >> n;
    my_type K;
    std::cin >> K;
    std::vector<my_type> elems;
    elems.reserve(n);
    while(n--) {
        my_type el;
        std::cin >> el;
        elems.push_back(el);
    }
    std::ranges::sort(elems);
    auto it = std::unique(elems.begin(), elems.end());
    elems.erase(it, elems.end());
    std::cout << binary_length(elems, K);
    return 0;
}