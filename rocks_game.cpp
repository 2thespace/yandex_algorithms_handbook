#include <iostream>
#include <string>


bool CheckWinCondition(int left, int right) {
    return (left ^ right) == 0;
}

std::string Rocks(int Left, int Right) {
    if(Left > Right) {
        std::swap(Left, Right);
    }
    std::string win_condition = "Win";
    if(CheckWinCondition(Left, Right) ) {
        std::string win_condition = "Loose";
    }

    return win_condition;
}

int main(int argc, char** argv) {
    int first, second;
    std::cout << (int)(8^2^10);
    std::cin >> first >> second;
    std::cout << Rocks(first, second) << std::endl;

    return 0;
}


