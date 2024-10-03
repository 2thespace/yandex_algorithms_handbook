#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <utility>
#define ENABLE_TEST

template<typename ...types>
class Foo {
public:
    Foo(std::size_t ...ids){
        
    }
private:
    std::unordered_map<std::size_t, types>
};


int main(int argc, char** argv) {
    Foo<int, char> f(std::make_pair(1,10), std::make_pair('1', 11));

}
