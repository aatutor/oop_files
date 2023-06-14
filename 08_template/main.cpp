#include <iostream>
#include <list>
using namespace std;


void Foo(int count, int t, ...){
	int* p = &t;
	while(count--){
		cout << *p <<" ";
		p++;
	}
	cout << endl;
}

int TempFoo(int x) {
	return x;
}
template <typename... T>
int TempFoo(int x, T... list){
	cout << x <<" ";
	return x + TempFoo(list...);	
}

int main ()
{
	Foo(5, 1,2,3,4,5);

	int s = TempFoo(1,2,3,4,5);
	cout << s << endl;

	list<int> li {10, 20, 30};
	for (auto el : li){
		cout << el << " ";
	}	
	cout << endl;

    return 0;
}
