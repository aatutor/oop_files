// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
using namespace std;


struct Arr{
    Arr(initialiser_list<int> list);

void Sort(int* a, int n);
void Print(int* a, int n);
int Sum(int* a, int n);
}

int main()
{
    Arr arr({1, 2, 2, 5, 3, 1});

    arr.Sort();
    arr.Print();
    cout << "summ: " << arr.Sum() << endl;

	return 0;
}