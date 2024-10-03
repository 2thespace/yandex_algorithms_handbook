#include <iostream>
#include <memory>

unsigned char* foo() {
    unsigned char * uptr = nullptr;
    uptr = new unsigned char(52);
    return uptr;    
}

int main(int argc, char** argv) {
    std::cout << "O" << std::endl;
    unsigned char* uptr = foo();
    delete uptr;
    *uptr = 100;
    std::cout << *uptr << std::endl;
    return 0;
}