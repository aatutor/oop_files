#include <iostream>
using namespace std;

class Array {
	int arr_[255];
	int size_ = 255;
public:
	Array(int size): size_(size) {}
	int GetElem(int ind) { return arr_[ind]; }
	void SetElem(int ind, int val) { arr_[ind] = val; }

	int& operator[] (int ind) {
		return arr_[ind];
	}
}

int main()
{
	Array a(3);
	a[0] = 1;
	cout << a[0] << endl;


	return 0;
}