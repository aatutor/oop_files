// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
using namespace std;


void Sort(int* a, int n);
void Print(int* a, int n);
int Sum(int* a, int n);

int main()
{
    int* arr = new int[6]{1, 2, 2, 5, 3, 1};

    Sort(arr, 6);
    Print(arr, 6);
    cout << "summ: " << Sum(arr, 6) << endl;

	return 0;
}