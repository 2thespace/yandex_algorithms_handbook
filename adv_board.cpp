#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


using my_type = long unsigned int;

template<typename T>
T max_cost(std::vector<std::pair<T,T>>& consumers, T week, T boards) {
    T total_cost{0};
    std::sort(consumers.begin(), consumers.end());
    std::size_t size = consumers.size() - 1;
    while(week--) {
        int boards_count = boards;
        int shift{0};
        while(boards_count) {
            if(consumers[size - shift].second != 0) {
                auto add_value = consumers[size - shift].first;
                consumers[size - shift].second--;
                total_cost += add_value;
                boards_count--;
            }
            else {
                shift++;
            }
            if(shift > size) break;
        }
    }
    return total_cost;
}



int main(int argc, char** argv) {
    int boards, k, w;
    std::cin >> boards >> k >> w;
    std::vector<std::pair<int, int>> consumers;
    consumers.reserve(k);
    while(k--) {
        int cost, weeks;
        std::cin >> cost >> weeks;
        consumers.emplace_back(cost, weeks);
    }

    std::cout << max_cost(consumers, w, boards) << std::endl;
    return 0;
}