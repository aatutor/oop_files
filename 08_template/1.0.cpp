#include <iostream>
using namespace std;

template <typename T>
void Sort(T arr[], int size)
{
	for (int k = size - 1; k > 0; k--)
		for (int j = 0; j < k; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}
template <typename T>
void Print(T arr[], int size) 
{
	for(int i = 0; i < size; i++)
		cout << arr[i] <<" ";
	cout << endl;
}

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
