#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

template<typename T>
std::vector<T> get_signed(std::vector<std::pair<T,T>> signs) {
    std::vector<T> result;
    std::ranges::sort(signs, [](std::pair<T,T>& a, std::pair<T, T>& b){return a.second > b.second;});
    while(!signs.empty())
    {
        auto r = signs.back().second;
        result.push_back(r);
        auto new_end = std::ranges::remove_if(signs, [&r](std::pair<T,T>& a){
            return (a.second >= r && a.first <= r);
        });
        signs.erase(new_end.begin(), signs.end());
    }
    return result;
}

int main(int argc, char ** argv) {

    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> signs;
    while(n--) {
        int l, r;
        std::cin >> l >> r;
        signs.emplace_back(l,r);
    }
    auto result = std::move(get_signed(signs));
    std::cout << result.size() << '\n';
    // Copy the elements except the last one with space
    std::ranges::copy(result.begin(), result.end() - 1, std::ostream_iterator<int>(std::cout, " "));

    // Print the last element with a newline
    if (!result.empty()) {
        std::cout << result.back() << '\n'; // Print last element followed by newline
    }
    return 0;
}