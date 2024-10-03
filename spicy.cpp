#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

double CalculateSpicy(uint W, std::vector<std::pair<uint,uint>>& spicys) {
    double max_spicy = 0;
    uint cost_index = 0;
    std::sort(spicys.begin(), spicys.end(), [](auto& first, auto& second) {
        double f = double(first.first)/first.second;
        double s = double(second.first)/second.second;
        std::cout << f << " " << s << std::endl;
        return f > s;
    });
    while (W > 0 && !spicys.empty()) {
        auto el = std::move(spicys[0]);
        if (el.second != 0) {
        {   uint amount = std::min(el.second, W);
            max_spicy += amount*(double)el.first/el.second;
            W-=amount;
        }
        spicys.erase(spicys.begin());
        }
    }
    return max_spicy;

}

int main(int argc, char ** argv) {
    uint w; // вместимость рюкзака
    uint n;
    std::cin >> n >> w;
    std::vector<std::pair<uint,uint>> spicys;
    while(n--) {
        uint cost, weight;
        std::cin >> cost >> weight;
        spicys.push_back({cost, weight});
    }

    std::cout << CalculateSpicy(w, spicys) << std::endl;

}

