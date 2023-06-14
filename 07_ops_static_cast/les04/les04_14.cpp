#include <iostream>

int max(int a, int b) { return a > b ? a : b; }
template <typename T1, typename T2> int max(T1 a, T2 b) = delete;

int main()
{
    std::cout << max(20, 30) << '\n';
    std::cout << max(20.5, 30) << '\n';
    std::cout << max('z', false) << '\n';
    std::cout << max('a', 'b') << '\n';

    return 0;
}