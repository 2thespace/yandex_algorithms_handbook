#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

// #define ENABLE_TEST

template<typename T>
std::ostream& operator <<(std::ostream& out, std::vector<T> const& v) {
    bool is_first = true;
    for(auto& el:v) {
         if(is_first) {
            is_first = !is_first;
         }
         else {
            out << ' ';
         }
         out << el;
    }
    return out;
}


void print(std::ostream& out, int value, int count) {
    for(int i = 0; i < count; ++i) {

        out << value << ' ';   
    }
    
}


std::string removeExtraSpaces(const std::string &input) {
    std::istringstream stream(input);
    std::string line, result;

    // Читаем каждую строку из входной строки
    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        std::string word;
        std::string processedLine;

        // Обрабатываем каждое слово в строке
        while (lineStream >> word) {
            if (!processedLine.empty()) {
                processedLine += " "; // добавляем пробел между словами
            }
            processedLine += word; // добавляем слово в результат
        }

        // Если в результате есть слова, добавляем их в итоговую строку
        if (!processedLine.empty()) {
            result += processedLine + "\n"; // добавляем строку с переносом
        }
    }

    return result;
}

std::string  exchange(int money) {
    std::ostringstream out;
    if(money == 0) return {};
    int count{0};
    // cout 10 5 and 1 
    // cout only 5 and 1
    for(auto ten = 0; ten <= money/10; ++ten) {
        
        auto five_count = (money - 10*ten)/5;
        for(auto five = 0; five <= five_count; ++ five) {
            count++;
            auto one = money - 10*ten-5*five;
            out << ten + five + one << ' ';
            print(out, 10, ten);
            print(out, 5, five);
            print(out, 1, one);
            out << '\n';    
        }
        
    }


    return {std::to_string(count) + '\n' + out.str()};
}
void Test()
{
#ifdef ENABLE_TEST
        std::cout << "Start tests" << std::endl;
    for(auto i = 1; i <= 1000; ++i) {
        auto ret = exchange(i);
        auto input_str = ret.str();
        auto remove_space =removeExtraSpaces(input_str);
        assert(remove_space.find("  ") == remove_space.npos);
        assert(remove_space.find("\n\n") == remove_space.npos);
        
    }
    std::cout << "Tests passed!" << std::endl;
#endif
}


int main(int argc, char ** argv) {
    Test();
    int money;
    std::cin >> money;
    auto ret = exchange(money);
    auto remove_space =removeExtraSpaces(ret);
    std::cout <<  remove_space;
    return 0;
}
