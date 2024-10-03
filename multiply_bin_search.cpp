#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <unordered_map>

 #define ENABLE_TEST

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

template<typename T>
std::vector<T> seq_bin_search(std::vector<T> const& first, std::vector<T> const& second) {
    std::vector<T> result(second.size(), -1);
    for(auto i = 0; i < second.size(); ++i) {
        auto index = binary_search(first, second[i]);
        if(index != -1) {
            result[i] = index;
        }
    }
    return result;
}

void Test() {
    #ifdef ENABLE_TEST
    std::vector<int>v{3};
    assert(v == seq_bin_search(std::vector<int>{1,3,7,8,9,12,15},std::vector<int>{8}));
    v = {0,5,1};
    assert(v == seq_bin_search(std::vector<int>{1,3,7,8,9,12,15}, std::vector<int>{1,12,3}));
    v = {1, -1, 0};
    assert(v == seq_bin_search(std::vector<int>{1,100000},std::vector<int>{100000, 54321, 1}));
    #endif
}

int main(int argc, char ** argv) {
    Test();
    using my_type = int;
    int n;
    std::cin >> n;
    std::vector<my_type> first_seq;
    first_seq.reserve(n);
    while(n--) {
        my_type el;
        std::cin >> el;
        first_seq.push_back(el);
    }
    std::cin >> n;
    std::vector<my_type> second_seq;
    second_seq.reserve(n);
    while(n--) {
        my_type el;
        std::cin >> el;
        second_seq.push_back(el);
    }
    // std::ranges::sort(second_seq);
    auto result = seq_bin_search(first_seq, second_seq);
    std::ranges::copy(result.begin(), result.end(), std::ostream_iterator<my_type>(std::cout, "\n"));
    //std::cout << 
    return 0;
}