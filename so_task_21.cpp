#include <iostream>
#include <string>

using namespace std;

#define P(x) std::cout << x << std::endl

class A1 {
    int i{ 5 };
public:
    explicit A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};

class V1 : virtual public A1 {
public:
    explicit V1(bool) : A1(true) { P("V1 c-tor"); }
    ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1 {
public:
    explicit C1(bool) : A1(true), V1(true) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }
};

class B2 {
public:
    explicit B2(bool) { P("B2 c-tor "); }
    virtual ~B2() { P("B2 d-tor"); }
};

class B3 {
public:
    explicit B3(bool) { P("B3 c-tor "); }
    virtual ~B3() { P("B3 d-tor"); }
};

class V2 : virtual public A1, public B2 {
public:
    explicit V2(bool) : A1(true), B2(true) { P("V2 c-tor"); }
    ~V2() override { P("V2 d-tor"); }
};

class C2 : virtual public V2, public B3 {
public:
    explicit C2(bool) : A1(true), V2(true), B3(true) { P("C2 c-tor"); }
    ~C2() override { P("C2 d-tor"); }
};

class M1 {
public:
    M1() { P("M1 c-tor"); }
    ~M1() { P("M1 d-tor"); }
};

class M2 {
public:
    M2() { P("M2 c-tor"); }
    ~M2() { P("M2 d-tor"); }
};

class X : public C1, public C2 {
    M1 m1;
    M2 m2;
public:
    X() : A1(true), V1(true), V2(true), C1(true), C2(true) { P("X c-tor"); }
    ~X() { P("X d-tor"); }
    // zaimplementuj c-tor i d-tor
};
int main() {
    A1* pa = new X;
    cout << pa->get() << endl; // zakomentować gdy public A1
    delete pa;
}