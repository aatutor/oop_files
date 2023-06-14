#include <iostream>
using namespace std;

struct Point {
	int x_, y_;
};

template <typename T, int size_>
class Array {
	T arr_[size_];
public:
	Array(T arr[]){
		for(int i = 0; i < size_; i++)
			arr_[i] = arr[i];
	}
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
	Array<int, 5> a(intArr);
	a.Sort();
	a.Print();

	char chrArr[]{"fdaslnvfjdkl"};
	Array<char, 12> c(chrArr);
	c.Sort();
	c.Print();

	Point points[]{ {1,2},{3,4},{5,6} };
	Array<Point, 3> p(points);
	// p.Sort();
	// p.Print();

    return 0;
}
