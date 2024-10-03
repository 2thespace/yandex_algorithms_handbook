#include <iostream>
#include <vector>


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


int main(int argc, char ** argv) {
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
    my_type find_el;
    std::cin>> find_el;
    std::cout << binary_search(elems, find_el) << std::endl;
    return 0;
}