#include <iostream>

#include <algorithm>
#include <vector>


using vector_lines = std::vector<std::pair<int, int>> ;

std::size_t eraseCross(vector_lines const& lines) {
    vector_lines tmp = lines;
    std::sort(tmp.begin(), tmp.end(), [](auto& left, auto& right){
        return left.second < right.second;
    });
    std::size_t noncross_count = 1;
    auto first_cross = tmp[0];
    for(auto& line : tmp) {
        if(line.second > first_cross.second && line.first > first_cross.second) {
            noncross_count++;
            first_cross = line;
        }
    }
    return noncross_count;
}



int main(int agrc, char** argv) {

#if 0
    vector_lines lines = { {1 , 2}, {2 , 3}, {4, 5}, {4, 5}, {5, 6} };
#else
    vector_lines lines;    
    int lines_count;
    std::cin >>  lines_count;
    lines.reserve(lines_count);
    while(lines_count--)
    {
        int first,second;
        std::cin >> first >> second;
        lines.emplace_back(first, second);
    }

#endif
    std::cout << eraseCross(lines) << std::endl;
    return 0;

}