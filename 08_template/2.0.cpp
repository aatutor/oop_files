#include <iostream>
using namespace std;

struct Point {
	int x_, y_;
};

template <typename T>
class Array {
	T* arr_;
	int size_;
public:
	Array(T arr[],int size): size_(size), arr_(new T[size]) {
		for(int i = 0; i < size_; i++)
			arr_[i] = arr[i];
	}
	~Array() { delete[] arr_; }
	void Sort(){
		for (int k = size_ - 1; k > 0; k--)
			for (int j = 0; j < k; j++)
				if (arr_[j] > arr_[j + 1])
					swap(arr_[j], arr_[j + 1]);
	}
	void Print() {
		for(int i = 0; i < size_; i++)
			cout << arr_[i] <<" ";
		cout << endl;
	}
};

int main ()
{
	int intArr[5]{153, 23, 543, 234, 43};
	Array<int> a(intArr, 5);
	a.Sort();
	a.Print();

	char chrArr[]{"fdaslnvfjdkl"};
	Array<char> c(chrArr, 12);
	c.Sort();
	c.Print();

	Point points[]{ {1,2},{3,4},{5,6} };
	Array<Point> p(points, 3);
	// p.Sort();
	// p.Print();

    return 0;
}
