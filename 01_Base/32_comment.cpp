// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

double Div(double a, double b) 
{
	if (b == 0)
		throw 1;

	return a / b;
}

void Test()
{
	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;

		cin >> b;
	#if 0
		if (b != 0)
			cout << (a / b) << endl;
		else
			cout << "Inf\n";
	#else
		try {
			cout << Div(a, b) << endl;
		}
		catch(int error) {
			cout << "Inf\n";
		}
	#endif
	}

	return 0;
}

int main ()
{
	Test();

	return 0;
}
