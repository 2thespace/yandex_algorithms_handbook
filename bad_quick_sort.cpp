#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <cassert>

#define ENABLE_TEST 1


template<typename T>
std::vector<T> forwardFillBadVariant(T n) {
    std::vector<T> result(n);
    std::vector<T> resultIdx(n);
    std::iota(resultIdx.begin(), resultIdx.end(), 0);
    auto r = resultIdx.size() - 1;
    for(;r > 0; --r) {
        auto mid = r/2;
        std::swap(resultIdx[mid], resultIdx[r]);
    }
    for(auto i = 0; i < resultIdx.size(); i++) {
        result[resultIdx[i]] = i + 1;
    }
    return result;
    
}

template<typename T>
std::vector<T> antiQsort(int n) {
    auto res = forwardFillBadVariant(n);
    return res;
}

template<typename T>
int partition(std::vector<T>& v, int low, int high) {
    auto& pivot = v[high];
    auto i = low - 1;
    for(int j = low ; j < high; ++j) {
        if(v[j] <= pivot) {
            i++;
            std::swap(v[j], v[i]);

        }
    }
    std::swap(v[i +1], v[high]);    
    return i + 1;
}

template<typename T>
int random_partition(std::vector<T>& v, int low, int high) {
    int random_index = low + std::rand()%(high - low);
    std::swap(v[random_index], v[high]);
    return partition(v, low, high);
}

template<typename T>
int mid_partition(std::vector<T>& v, int low, int high) {
    int random_index = (low + high)/2;
    std::swap(v[random_index], v[high]);
    return partition(v, low, high);
}



template<typename T>
void QuickSort(std::vector<T>&v, int low, int high, int& i) {
    if(low >= high) return;
        ++i;
        auto index = mid_partition(v, low, high);
        QuickSort(v, low, index - 1, i);
        QuickSort(v, index + 1, high, i);
}  

void Tests() {
    #if ENABLE_TEST
    for(auto i = 2; i <= 1000; i++) {
        int j = 0;
        auto res = antiQsort<int>(i);
        QuickSort(res, 0, res.size() - 1, j);
        assert(j == (i-1));
    }
    #endif
}

int main(int argc, char** argv) {
    Tests();
    int n;
    std::cin >> n;
    auto res = antiQsort<int>(n);
    std::ranges::copy(res, std::ostream_iterator<int>{std::cout, " "} ); std::cout <<  std::endl;

    return 0;
}
