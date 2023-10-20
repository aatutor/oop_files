class B {};

class A {
public:
    void m1();
    // void m1(int*);
    // void m1(bool*);
// private:
//     B* m1(B*);
};

void A::m1() {}
// void A::m1(int* x) {}
// B* A::m1(B* x) {}