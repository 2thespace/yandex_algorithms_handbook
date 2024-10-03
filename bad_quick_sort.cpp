#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>

#define ENABLE_TEST 0


template<typename T>
void fillBadEl(std::vector<T> & v, int l, int r) {
    if(l>= r) return;
    auto mid = (l+r)/2;
    fillBadEl(v, mid +1 , r); 
#if ENABLE_TEST
    std::cout << l << " " << r  << " " << mid << " | ";
    std::copy(&v[l], &v[r+1], std::ostream_iterator<T>{std::cout, " "}); std::cout << std::endl;
#endif 
    auto it = std::max_element(&v[l], &v[r+1]);
    std::iter_swap(it, &v[mid]);
}



template<typename T>
std::vector<T> forwardFillBadVariant(T n) {
    std::vector<T> result(n);
    std::vector<T> resultIdx(n);
    std::iota(resultIdx.begin(), resultIdx.end(), 0);
    int r = result.size() -1;
    for(auto l = 0; l < r; ++l) {
        auto mid = (l+r)/2;
        std::swap(resultIdx[mid], resultIdx[r]);
    }

    for(auto i = 0; i <n; ++i) {
        result[resultIdx[i]] = i + 1;
    }


    return result;
    
}

template<typename T>
std::vector<T> antiQsort(int n) {
    std::vector<T> result(n);
    std::iota(result.begin(), result.end(), 1);
    fillBadEl(result, 0, result.size() - 1);
    // auto res = forwardFillBadVariant(n);
    return res;
}

template<typename T>
int partition(std::vector<T>& v, int low, int high) {
    auto& pivot = v[high];
#if ENABLE_TEST
    std::cout << "-------------------------\nmid = " << pivot << " low = "<< low << " high = " << high << std::endl;
    std::ranges::copy(v, std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
#endif
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
void QuickSort(std::vector<T>&v, int low, int high, int& i) {
    if(low >= high) return;
        ++i;
        auto index = random_partition(v, low, high);
        QuickSort(v, low, index - 1, i);
        QuickSort(v, index + 1, high, i);
}  


int main(int argc, char** argv) {

    int n;
    std::cin >> n;
    auto res = antiQsort<int>(n);
    std::ranges::copy(res, std::ostream_iterator<int>{std::cout, " "} ); std::cout <<  std::endl;
    int i{0};
    QuickSort(res, 0, res.size()-1, i);
    std::cout << i << std::endl;
    std::ranges::copy(res, std::ostream_iterator<int>{std::cout, " "} ); std::cout <<  std::endl;
    return 0;
}
