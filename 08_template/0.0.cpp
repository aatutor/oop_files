#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {
	return (a > b) ? a : b ;
}

int main ()
{
	cout << Max(3, 5) << endl;
	cout << Max(3.4, 5) << endl;

	cout << Max(3.5, 3.3) << endl;
	cout << Max('h', 'e') << endl;

    return 0;
}
