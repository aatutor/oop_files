#include <iostream>
using namespace std;

void Foo(int count, int t, ...){
	int* p = &t;
	while(count--){
		cout << *p <<" ";
		p++;
	}
	cout << endl;
}
template <typename T>
void Foo(initializer_list<T> list){
	for(int el : list)
	{
		cout << el << " ";
	}
	cout << endl;
}

template <typename T>
void Foo(initializer_list<T> list) {
	auto ptr = list.begin();
	for(int i = 0; i < list.size(); i++)
	{
		cout << ptr[i] <<" ";
	}
	cout << endl;
}
template <typename T>
void Foo(initializer_list<T> list) {
	auto* ptr = list.begin();
	while (ptr != list.end()){
		cout << *ptr <<" ";
		ptr++;
	}
	cout << endl;
}

int main ()
{
	Foo(4, 1,2,3,4);
	Foo({10, 15, 25, 135});

	std::initializer_list<int> list{1,2,3};
	Foo(list);

    return 0;
}
