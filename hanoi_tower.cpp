#include <cmath>
#include <iostream>
#include <string_view>

void hanoi(int n, char from_rod, char to_rod, char tmp_rod) {
    if(n == 1) {
        std::cout << from_rod << " " << to_rod << std::endl;
        return;
    }
    hanoi(n - 1, from_rod, tmp_rod, to_rod);
    std::cout << from_rod << " " << to_rod << std::endl;
    hanoi(n-1, tmp_rod, to_rod, from_rod);
}

int hanoi_count(int n) {
    
    if(n == 1)
        return 1;
    return 2*hanoi_count(n-1) + 1;
}

int frameStewart(int n, int k) {
    // Базовые случаи
    if (n == 0) return 0; // Нет дисков для перемещения
    if (n == 1) return 1; // Один диск перемещается за один ход
    if (k == 1) return  __INT_MAX__; // Невозможно переместить диски с одним стержнем
    if (k == 3) return (1 << n) - 1; // Классическая задача Ханойской башни

    int minMoves = __INT_MAX__;

    // Перебираем количество дисков, которые будут перемещены на промежуточный стержень
    for(int i =1; i < n; i++)
    {
        int moves = 2*frameStewart(i, k) + frameStewart(n - i, k - 1);
        if (moves < minMoves) {
            minMoves = moves;
        }
    }

    return minMoves;
}


int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::cout << frameStewart(n, 4) << std::endl;
    // hanoi(n, '1', '3', '2');
    return 0;
}