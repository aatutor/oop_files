// https://en.cppreference.com/w/cpp/container/vector
// https://en.cppreference.com/w/cpp/container/list
// https://en.cppreference.com/w/cpp/container/map
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> v; // init

    // input
    v.push_back(1);
    v.push_back(4);

    for (auto elem : v){
        cout << elem << " ";
    }
    return 0;
}

void more_vect(){
    std::vector<int> v1;                // пустой вектор
    std::vector<int> v2(v1);            // вектор v2 - копия вектора v1
    std::vector<int> v3 = v1;           // вектор v3 - копия вектора v1
    std::vector<int> v4(5);             // вектор v4 состоит из 5 чисел
    std::vector<int> v5(5, 2);          // вектор v5 состоит из 5 чисел, каждое число равно 2
    std::vector<int> v6{1, 2, 4, 5};    // вектор v6 состоит из чисел 1, 2, 4, 5
    std::vector<int> v7 = {1, 2, 3, 5}; // вектор v7 состоит из чисел 1, 2, 4, 5

    std::vector<int> v1(5);       // вектор состоит из 5 чисел, каждое число в векторе равно 0
    std::vector<int> v2{5};       // вектор состоит из одного числа, которое равно 5
    std::vector<int> v3(5, 2);    // вектор состоит из 5 чисел, каждое число равно 2
    std::vector<int> v4{5, 2};    // вектор состоит из двух чисел 5 и 2
}