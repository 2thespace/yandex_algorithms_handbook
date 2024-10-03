#include <algorithm>
#include<cassert>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>

template<typename T>
std::ostream& operator<< (std::ostream& out, std::vector<T> const& v) {
    for(auto& el : v) {
        out << el << " ";
    }
    out << std::endl;
    return out;
}

void selection_sort(std::vector<int>& array, int start_number) {
    if(start_number == array.size() - 1) {
        return;
    }
    int lowest_pos = start_number;
    for(int i = start_number + 1; i < array.size(); ++i) {
        if(array[i] < array[lowest_pos]) {
            lowest_pos = i;
        }
    }
    std::swap(array[start_number], array[lowest_pos]);
    selection_sort(array, ++start_number);
}

template<typename T>
std::vector<T> Merge(std::vector<std::vector<T>> const& sequences) {
    std::vector<std::size_t> ptr_count(sequences.size(), 0);
    auto full_size = std::accumulate(sequences.begin(), sequences.end(), 0, [](int sum, auto& v)
        {
            return sum + v.size();
        }
    );
    std::vector<T> merge_sequence{};
    merge_sequence.reserve(full_size);
    bool end_condition = true;
    while(end_condition) {
        T min_element = std::numeric_limits<T>::max();
        int min_index = 0;
        // find min element
        for(int i = 0; i < ptr_count.size(); ++i) {
            if(ptr_count[i] == sequences[i].size()) {
                continue;
            }
            if( sequences[i][ptr_count[i]] < min_element)
            {
                min_element = sequences[i][ptr_count[i]];
                min_index = i;
            }

        }
        merge_sequence.push_back(min_element);
        ptr_count[min_index] = std::min(ptr_count[min_index] + 1 , sequences[min_index].size());
        // check condition
        bool flag = false;
        for(int i = 0; i < sequences.size(); ++i) {
            flag |= ptr_count[i] != (sequences[i].size()); 
        }
         end_condition &= flag;
    }
    return merge_sequence;
}
template<typename T>
std::vector<T> MergeSort(std::vector<T> const& input_array) {
    if(input_array.size() == 1) {
        return input_array;
    }
    auto first_diap = input_array.size()/2;
    auto first = MergeSort<T>({input_array.begin(), input_array.begin() + first_diap});
    auto second = MergeSort<T>({input_array.begin() + first_diap, input_array.end()});
    return Merge<T>({first, second});


}

void UnitTest()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<unsigned int> tst(1'000'000);
    std::iota(tst.rbegin(), tst.rend(), 0);
    // std::generate(tst.begin(), tst.end(), g);
    std::vector<unsigned int> copy_tst = tst;
    auto tick1 = std::chrono::system_clock::now();
    std::sort(tst.begin(), tst.end());
    auto tick2 = std::chrono::system_clock::now();
    auto srt = std::chrono::duration_cast<std::chrono::milliseconds>(tick2 - tick1);
    std::cout << "sort: " << srt.count() << " ms" << std::flush;
    copy_tst = MergeSort(copy_tst);
    auto tick3 = std::chrono::system_clock::now();
   
    auto qsrt = std::chrono::duration_cast<std::chrono::milliseconds>(tick3 - tick2);
    std::cout << " msort " << qsort << qsrt.count() << " ms" << std::endl;
    assert(tst == copy_tst);
    
 }

int main(void) {
    UnitTest();
    int array_count;
    std::cin >> array_count;

    std::vector<int> unsorted_arr;
    unsorted_arr.reserve(array_count);
    while(array_count--) {
        int elem;
        std::cin >> elem;
        unsorted_arr.push_back(elem);
    }

    std::cout << MergeSort(unsorted_arr);
}

