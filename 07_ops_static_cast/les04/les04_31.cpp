#include <iostream>

class Fraction
{
    int numerator;
    int denominator;
    int gcd(int a, int b);
    void reduce();
public:
    Fraction(int num, int denom)
        : numerator{ num }, denominator{ denom ? denom : 1 }
    {
        reduce();
    };
    Fraction() : Fraction(1, 1) {};
    void setNumerator(int num) { numerator = num; reduce(); };
    int getNumerator() const { return numerator; };
    void setDenominator(int denom) { denominator = denom ? denom : 1; reduce(); };
    int getDenominator() const { return denominator; }
    void print() const;
};

int Fraction::gcd(int a, int b)
{
    int copy;
    while (b)
    {
        a %= b;
        copy = a;
        a = b;
        b = copy;
    }
    return a;
}

void Fraction::reduce()
{
    int gcdVal{ gcd(numerator, denominator) };
    numerator /= gcdVal;
    denominator /= gcdVal;

    if (denominator < 0 and numerator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }
}

void Fraction::print() const
{
    std::cout << '(' << numerator << " / " << denominator << ")";
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
    return Fraction{ left.getNumerator() * right.getDenominator() + right.getNumerator() * left.getDenominator(), left.getDenominator() * right.getDenominator() };
}

Fraction operator+(const Fraction& left, int right)
{
    return Fraction{ left.getNumerator() + right * left.getDenominator(), left.getDenominator() };
}

Fraction operator+(int left, const Fraction& right)
{
    return right + left;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
    return Fraction{ left.getNumerator() * right.getDenominator() - right.getNumerator() * left.getDenominator(), left.getDenominator() * right.getDenominator() };
}

Fraction operator-(const Fraction& left, int right)
{
    return Fraction{ left.getNumerator() - right * left.getDenominator(), left.getDenominator() };
}

Fraction operator-(int left, const Fraction& right)
{
    return Fraction{ left * right.getDenominator() - right.getNumerator(), right.getDenominator() };
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
    return Fraction{ left.getNumerator() * right.getNumerator(), left.getDenominator() * right.getDenominator() };
}

Fraction operator*(const Fraction& left, int right)
{
    return Fraction{ left.getNumerator() * right, left.getDenominator() };
}

Fraction operator*(int left, const Fraction& right)
{
    return right * left;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
    return Fraction{ left.getNumerator() * right.getDenominator(), left.getDenominator() * right.getNumerator() };
}

Fraction operator/(const Fraction& left, int right)
{
    return Fraction{ left.getNumerator() , left.getDenominator() * right };
}

Fraction operator/(int left, const Fraction& right)
{
    return Fraction{ left * right.getDenominator(), right.getNumerator() };
}

int main()
{
    Fraction a{ 1,2 };
    Fraction b{ 1,3 };

    std::cout << "a = "; a.print(); std::cout << " b = "; b.print(); std::cout << '\n';
    std::cout << "a + b = "; (a + b).print(); std::cout << '\n';
    std::cout << "a - b = "; (a - b).print(); std::cout << '\n';
    std::cout << "a * b = "; (a * b).print(); std::cout << '\n';
    std::cout << "a / b = "; (a / b).print(); std::cout << '\n';

    std::cout << "a + 3 = "; (a + 3).print(); std::cout << '\n';
    std::cout << "3 + a = "; (3 + a).print(); std::cout << '\n';
    std::cout << "a - 3 = "; (a - 3).print(); std::cout << '\n';
    std::cout << "3 - a = "; (3 - a).print(); std::cout << '\n';

    std::cout << "a * 3 = "; (a * 3).print(); std::cout << '\n';
    std::cout << "3 * a = "; (3 * a).print(); std::cout << '\n';
    std::cout << "a / 3 = "; (a / 3).print(); std::cout << '\n';
    std::cout << "3 / a = "; (3 / a).print(); std::cout << '\n';

    return 0;
}