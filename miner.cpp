#include <iostream>
#include <vector>
#include <sstream>

template<std::ostream& out>
void printSurface(std::vector<std::vector<int>>& surface) {
    for(auto& v:surface) {
        bool is_first = true;
        for(auto point:v) {
            
            if(is_first) {
                is_first = false;
            }
            else {
                out << ' ';
            }
            if(point == -1) {
                out << '*';
            }
            else {
                out << point;
            }
        }
        out << std::endl;
    }
}

int main() {
    int m,n,k;
    std::cin >> m >> n >> k;    
    std::vector<std::vector<int>> surface(m, std::vector<int>(n,0));
    while(k--) {
        int x,y;
        std::cin >> x >> y;
        y-=1; x-=1;
        if(x < 0 || y < 0) continue;
        surface[x][y] = -1;
        for(auto dx = -1; dx <=1; ++dx)
        {
            auto point_x = x + dx;
            for(auto dy = -1; dy <= 1; ++dy) {
                auto point_y = y + dy;
                if(point_y < 0 || point_x < 0 || point_x >= m || point_y >= n) continue;
                if(surface[point_x][point_y] == -1) continue;
                surface[point_x][point_y]+=1;
            }
        }
    }
    printSurface<std::cout>(surface);
    return 0;
}