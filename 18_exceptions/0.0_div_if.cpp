#include <iostream>
using namespace std;

int main ()
{
	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;

		cin >> b;
		if (b != 0)
			cout << (a / b) << endl;
		else
			cout << "Inf\n";
	}

	return 0;
}

/*
input: 1 2
0.5
input: 1 3
0.333333
input: 2 0
Inf
input: 3 4
0.75
input: 0
*/
