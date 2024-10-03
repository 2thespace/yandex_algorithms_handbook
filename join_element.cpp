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
int lower_bound(std::vector<T> const& v, T elem) {
    int head = 0;   
    int tail = v.size() - 1;
    int index = -1;
    while(head <= tail) {
        auto mid =  (tail + head)/2;
        if(v[mid] == elem) {
            tail = mid - 1;
            index = mid;
        }
        else if(v[mid] > elem) {
            tail =  mid -1;

        }
        else {
            head = mid + 1;

        }
    }
    return index;
}


template<typename T>
int upper_bound(std::vector<T> const& v, T elem) {
    int head = 0;   
    int tail = v.size() - 1;
    int index = -1;
    while(head <= tail) {
        auto mid =  (tail + head)/2;
        if(v[mid] == elem) {
            head = mid + 1;
            index = mid;
        }
        else if(v[mid] > elem) {
            tail =  mid -1;

        }
        else {
            head = mid + 1;

        }
    }
    return index == -1 ? index : index+1;
}

template<typename T>
int dist_el(std::vector<T> const& K, T q) {
    return upper_bound(K, q) - lower_bound(K,q);
}

template<typename T>
std::vector<T> join_count(std::vector<T> const& K, std::vector<T> const& q) {
    std::vector<T> result;
    result.reserve(q.size());
    for(auto& q_el:q ) {
        result.push_back(dist_el(K, q_el));
    }
    return result;
}

void Test() {
#ifdef ENABLE_TEST
    std::vector<int> t{1,2,2,2,7};
    assert(1==lower_bound(t, 2));
    assert(4==upper_bound(t, 2));
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
        auto result = join_count(first_seq, second_seq);
    std::ranges::copy(result, std::ostream_iterator<my_type>(std::cout, " "));
    return 0;
}