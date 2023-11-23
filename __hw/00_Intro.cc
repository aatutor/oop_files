
struct DFraction {
private:
    int ch_;
    int zn_;
public:
    void Init(int a, int b);
    double Sum(Fraction);
    double Sub(Fraction);
    double Mult(Fraction);
    double Div(Fraction);
};
// or
struct Fraction {
private:
    int ch_;
    int zn_;
public:
    void Init(int a, int b);
    Fraction Sum(Fraction);
    Fraction Sub(Fraction);
    Fraction Mult(Fraction);
    Fraction Div(Fraction);
};