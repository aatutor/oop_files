#include <iostream>
#include <vector>
//using namespace std;
using std::cout;
using std::endl;

void err_int();
void err_str();
void err_any(int);
void err_out_of_range(int);

int main()
{
	err_int();
	err_str();

	err_any(0);
	err_any(1);
	err_any(2);

	err_out_of_range(10);
	err_out_of_range(20);

	cout << "\n:\tprogram is finished, against errors\n";
	return 0;
}

void err_int() {
	try {
		throw 404;
		cout << "after";
	}
	catch (int err) {
		cout << "Error with code: " << err << endl;
	}
}

void err_str() {
	try {
		throw "Simple error :3";
		throw "Hard ERROR!!!";
	}
	catch (const char* err) {
		cout << err << endl;
	}
}

void err_any(int x) {
	try {
		if (x == 0)
			throw 55;
		if (x == 1)
			throw "Error one!!!!11111";
		throw true;
	}
	catch (int err) {
		cout << "Error with code:) " << err << endl;
	}
	catch (const char* err) {
		cout << err << endl;
	}
	catch (...) {
		cout << "Unknown error =(\n";
	}

}

struct Arr {
	static const int SIZE = 20;
	int arr[SIZE];

	int& operator[] (int i) {
		if ((i >= SIZE) or (i < 0))
			throw std::out_of_range{ "More when 19 index" };
		return arr[i];
	}
};
//	https://evileg.com/ru/post/289/
void err_out_of_range(int ind) {
	Arr arr;
	try {
		cout << "I can get: " << arr[ind] << endl;
	}
	catch (std::exception err) {
		cout << "No. U can't take more: " << err.what() << endl;
	}
	catch (...) {
		cout << "or can't other reson\n";
	}
}
