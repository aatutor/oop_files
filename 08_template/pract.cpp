#include <iostream>
using namespace std;

template <typename T>
class Array {
	T* arr_;
	int size_;
public:
	Array(initializer_list<T> list);
	~Array();

	void Print();
};

int main ()
{
	Array<int> arr5({1,2,3,4,5});

    return 0;
}
