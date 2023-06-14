#include <iostream>
using namespace std;

template <typename T>
T* Geterate(int size) {
	return new T[size] {};
}

template <typename T>
void Sort(T arr[], int size);

template <typename T>
void Print(T arr[], int size); 

int main ()
{
	int intArr[5]{153, 23, 543, 234, 43};
	Sort(intArr, 5);
	Print(intArr, 5);

	char chrArr[]{"fdaslnvfjdkl"};
	Sort(chrArr, 12);
	Print(chrArr, 12);

    return 0;
}
