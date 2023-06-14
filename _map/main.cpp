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
    std::vector<int> v1;                // ������ ������
    std::vector<int> v2(v1);            // ������ v2 - ����� ������� v1
    std::vector<int> v3 = v1;           // ������ v3 - ����� ������� v1
    std::vector<int> v4(5);             // ������ v4 ������� �� 5 �����
    std::vector<int> v5(5, 2);          // ������ v5 ������� �� 5 �����, ������ ����� ����� 2
    std::vector<int> v6{1, 2, 4, 5};    // ������ v6 ������� �� ����� 1, 2, 4, 5
    std::vector<int> v7 = {1, 2, 3, 5}; // ������ v7 ������� �� ����� 1, 2, 4, 5

    std::vector<int> v1(5);       // ������ ������� �� 5 �����, ������ ����� � ������� ����� 0
    std::vector<int> v2{5};       // ������ ������� �� ������ �����, ������� ����� 5
    std::vector<int> v3(5, 2);    // ������ ������� �� 5 �����, ������ ����� ����� 2
    std::vector<int> v4{5, 2};    // ������ ������� �� ���� ����� 5 � 2
}