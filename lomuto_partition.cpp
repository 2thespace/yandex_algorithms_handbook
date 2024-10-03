#include <algorithm>
#include<cassert>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <iterator>

template<typename T>
std::ostream& operator<< (std::ostream& out, std::vector<T> const& v) {
    for(auto& el : v) {
        out << el << " ";
    }
    out << std::endl;
    return out;
}

template<typename T>
void fillBiggestMedian(std::vector<T>& v, int low, int high, int n) {
    if(low < high) {
        auto mid = (low + high)/2;
        fillBiggestMedian(v, mid+1, high);  
        fillBiggestMedian(v, low, mid-1);
        
        
        std::cout << std::endl;
    }

}

template<typename T>
int partition(std::vector<T>& v, int low, int high) {
    auto mid = (low + high)/2;
    auto& pivot = v[mid];
    std::cout << "-------------------------\nmid = " << pivot << " low = "<< low << " high = " << high << std::endl;
    std::ranges::copy(v, std::ostream_iterator<T>(std::cout, " "));
    auto i = low - 1;
    for(int j = low ; j < high; ++j) {
        if(v[j] <= pivot) {
            i++;
            std::swap(v[j], v[i]);

        }
    }
    std::swap(v[i +1], v[mid]);
    
    std::cout << std::endl;
    return i + 1;
}

template<typename T>
int random_partition(std::vector<T>& v, int low, int high) {
    int random_index = low + std::rand()%(high - low);
    std::swap(v[random_index], v[high]);
    return partition(v, low, high);
}


template<typename T>
void QuickSort(std::vector<T>&v, int low, int high) {
    if(low < high) {
        auto index = partition(v, low, high);
        QuickSort(v, low, index - 1);
        QuickSort(v, index + 1, high);
    }
    return;

}  

template<typename T>
std::vector<T> unfstSort(int n) {
    std::vector<T> v(n);
    std::iota(v.begin(), v.end(), 1);
    // for(auto i = 0; i < v.size(); ++i) {
    //     auto mid = (i)/2;
    //     std::swap(v[i], v[mid]);
    // }
    fillBiggestMedian(v, 0, v.size()-1, v.size());
    return v;
}



int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    auto v = unfstSort<int>(n);
    std::cout << v;
    QuickSort(v, 0, v.size()-1);
    std::cout << "Sort result " << v << std::endl;
    return 0;
}