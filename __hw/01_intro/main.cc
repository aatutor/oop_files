// Реализуйте класс Дробь (Fraction).
// Необходимо хранить числитель и
// знаменатель в качестве полей
// (переменных-членов). Реализуйте
// методы (функции-члены) для ввода
// данных в поля, для выполнения
// арифметических операций:
// - сложение(Sum)
// - вычитание(Sub)
// - умножение(Mult)
// - деление(Div)

#include "Fraction.cpp"
#include <iostream>

void TestNum() 
{
    using namespace std;
    Fraction f1, f2;
    f1.Init(1, 2);
    f2.Init(3, 4);
    cout << f1.Sum(f2) << endl;
}

int main()
{
    TestNum();

    return 0;
}