#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


using my_type = long unsigned int;

template<typename T>
T max_cost(std::vector<T>& prices, std::vector<T>& clicks ) {
    T total_cost{0};
    std::sort(prices.begin(), prices.end());
    std::sort(clicks.begin(), clicks.end());
    for(auto i = 0; i < prices.size(); ++i) {
        total_cost += prices[i] * clicks[i];
    }
    return total_cost;
}

int main(int argc, char** argv) {
    std::vector<my_type> prices;
    std::vector<my_type> clicks;
    my_type n;
    std::cin >> n;
    prices.reserve(n);
    clicks.reserve(n);
    for(auto i = 0; i < n; ++i) {
        my_type number;
        std::cin >> number;
        prices.push_back(number);
    }
    for(auto i = 0; i < n; ++i) {
        my_type number;
        std::cin >> number;
        clicks.push_back(number);
    }
    std::cout << max_cost(prices, clicks) << std::endl;
    return 0;
}