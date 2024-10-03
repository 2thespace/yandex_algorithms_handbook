#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>
#include <cassert>
#include <cmath>

#define ENABLE_TEST

int main(int argc, char ** argv) {

    int n, candidate;
    std::cin >> n >> candidate;
    std::vector<int> a_i;
    a_i.reserve(n);
    while(n--) {
        int a;
        std::cin >> a;
        a_i.push_back(a);
    }
    auto cur_score = a_i[candidate-1];
    std::ranges::sort(a_i);
    auto pos = std::ranges::find(a_i, cur_score);
    auto lose_dist = pos - a_i.begin();
    auto win_dist = a_i.end() - (pos + 1);
    std::size_t result{a_i.size()%2};

    while(lose_dist) {
        if(win_dist%2) {
            lose_dist -=1;
        }
        lose_dist/=2;
        win_dist/=2;
        result++;
    }
    std::cout << result << std::endl;
    return 0;
}