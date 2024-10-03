#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

#define ENABLE_TEST




std::string optimal_exchenge(int money) {
    const int fifty = 50;
    const int twenty = 20;
    const int ten = 10;
    const int five  = 5;
    std::string output{};
    int count = 0;
    while(money >= five) {
        int mod = 1;
        if(money >= fifty) {
            mod = fifty;
        }
        else if(money >= twenty) {
            mod = twenty;
        }
        else if(money >= ten) {
            mod = 10;
        }
        else if(money >= five) {
            mod = five;
        }
        money -= mod;
        output += std::to_string(mod) + ' ';
        count++;
    }
    for(auto i = 0; i < money; ++i) {
        output += std::to_string(1) + ' ';
    }
    return {std::to_string(count + money) + '\n' + output + '\n'};
}

void Test()
{
#ifdef ENABLE_TEST
    using namespace std::string_literals;
    assert("3\n5 1 1 \n"s == optimal_exchenge(7));
    assert("1\n10 \n"s == optimal_exchenge(10));
    assert("1\n1 \n"s == optimal_exchenge(1));
    assert("3\n50 50 5 \n"s == optimal_exchenge(105));
#endif
}


int main(int argc, char ** argv) {
    Test();
    int money;
    std::cin >> money;
    std::cout << optimal_exchenge(money);
    return 0;
}
