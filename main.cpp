#include <iostream>
#include <vector>

std::size_t PrintVPtr(void *obj);

class Base
{
public:
    Base()
    {   SetVtable(this);
        std::cout<< "Base Ctor vptr: " << std::hex << GetVtable()  << std::endl;
    }
    void Foo() 
    {
         GetVtable()->foo_ptr(this);
    }
    ~Base()
    {

        std::cout<< "Base Dtor vptr: " << std::hex << GetVtable()   << std::endl;;
    }
    struct Vtable{
        void(*foo_ptr) (Base *);
    };

    static void SetVtable(Base *obj) {
        *(Vtable**)obj = &vtable_;
    }

    Vtable* GetVtable(void) {
        return vptr_;
    }

    const Vtable* GetVtable(void) const{
        return vptr_;
    }

private:
    Base::Vtable* vptr_ = nullptr;
    static Vtable vtable_;


    static void Foo(Base* obj) 
    {
        std::cout << "Base foo" << std::endl;
    }
    
};

Base::Vtable Base::vtable_ = {Base::Foo};

class Derive /*: public Base*/
{
public:
    Derive():base_()
    {
        SetVtable(this);
        std::cout<< "Derive Ctor vptr: " << std::hex << GetVtable()  << std::endl;
    }
    void Foo() 
    {
        GetVtable()->foo_ptr(this);
    }

    ~Derive()
    {
        std::cout<< "Derive Dtor vptr: " << std::hex << GetVtable()  << std::endl;
    }

    struct Vtable{
        void(*foo_ptr) (Derive *);
    };

private:
    Base base_;
    static Vtable vtable_;

    static void SetVtable(Derive* obj) {
        *(Vtable**)obj = &vtable_;
    }

    Vtable* GetVtable(void) {
        return (Derive::Vtable*)base_.GetVtable();
    }

    const Vtable* GetVtable(void) const{
        return (Derive::Vtable*)base_.GetVtable();
    }

    static void Foo(Derive* obj) 
    {
        std::cout << "Derive foo" << std::endl;
    }
};

Derive::Vtable Derive::vtable_ = {Foo};


struct Test 
{
    int a;
    int b;
};

// int main(void) {

//     // Derive a;

//     // Base a1;
//     // std::vector<Base*> v =  { (Base*)&a, (Base*)&a1};
//     // for(auto& a: v)
//     // {
//     //     a->Foo();
//     // }

//     Test boo;
//     Test* foo = &boo;
//     foo->a = 5;
//     foo->b = 6;
//     std::cout << foo->a << " " << foo->b << std::endl;
// }

int main() {

    int ms = 206578;
    int s = ms/1000;
    std::cout << s/60 << " m " << s%60 << " s" << std::endl;

    std::vector<int> v;
    v.reserve(10);
    v.push_back(1);

    return 0;

}