#include <iostream>
using namespace std;

class Array {
	int arr_[255];
	int size_ = 255;
public:
	Array(int size): size_(size) {}
	int GetElem(int ind) { return arr_[ind]; }
	void SetElem(int ind, int val) { arr_[ind] = val; }
	void Print() {
		for(int i = 0; i < size_; i++)
			cout << arr_[i] <<" ";
		cout << endl;
	}

	int& operator[] (int ind) {
		return arr_[ind];
	}
	void operator() (int ind, int val) {
		arr_[ind] = val;
	}
	int& operator() (int ind) {
		return arr_[ind];
	}
};

int main()
{
	Array a(3);
	a[0] = 1;
	a(1, 2);
	a(2) = 3;
	a.Print();

	return 0;
}