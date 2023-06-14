#include <iostream>
using namespace std;

template <typename T>
void Sort(T arr[], int size);
// void Sort(int arr[], int size);
// void Sort(char arr[], int size);

template <typename T>
void Print(T arr[], int size); 
// void Print(int arr[], int size); 
// void Print(char arr[], int size); 

int main ()
{
	int intArr[5]{153, 23, 543, 234, 43};
	Sort<int>(intArr, 5);
	Print<int>(intArr, 5);

	char chrArr[]{"fdaslnvfjdkl"};
	Sort<char>(chrArr, 12);
	Print<char>(chrArr, 12);

    return 0;
}
