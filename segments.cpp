#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>


template<typename T>
T min_length(std::vector<T>& points, T length_count) {
    if(length_count > points.size()) return 0;
    std::ranges::sort(points);
    // find biggest dist between two neigh points
    std::vector<std::pair<T, T>> dist_p; // vector of {dist_p1p2,p1_x}
    for(auto i = 0; i != points.size() - 1; ++i) {
        dist_p.emplace_back(points[i+1] - points[i], i);
    }
    std::ranges::sort(dist_p, std::ranges::greater());
    length_count -=1;
    std::ranges::sort(dist_p | std::views::take(length_count), {}, [](const auto& p) { return p.second; });
    int first_index = 0;
    T length{0};
    while(length_count--) {
        auto current_index = dist_p.front().second; 
        length += points[current_index] - points[first_index];
        dist_p.erase(dist_p.begin());
        first_index = std::min(current_index + 1, (int)points.size()-1);
    }
    length += points[points.size() - 1] - points[first_index];
    return length;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> points;
    points.reserve(n);
    while(n--) {
        int point;
        std::cin >> point;
        points.push_back(point);
    }

    std::cout << min_length(points, k) <<'\n';
    return 0;
}
