#include <iostream>
#include <vector>
//using namespace std;
using std::cout;
using std::endl;

void err_int();
void err_str();
void err_any(int);
void err_out_of_range();

int operator+ (int a, int b) {
	cout << "sum: " << a << " + " << b<< endl;
	return a+b;
}

int main()
{
	cout << 4+5 << endl;
	err_int();
	err_str();
	
	err_any(0);
	err_any(1);
	err_any(2);
	
	err_out_of_range();

	cout << "\n:\tprogram is finished, against errors\n";
	return 0;
}

void err_int() {
	try {
		throw 404;
	}
	catch (int err) {
		cout << "Error with code: " << err << endl;
	}
}

void err_str() {
	try {
		throw "Simple error :3";
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
		cout << "Unknown error =(";
	}

}

struct Arr {
	static const int SIZE = 20;
	int arr[SIZE];

	int& operator[] (int i) {
		if (i >= SIZE) 
			throw std::out_of_range{"More when 19 index"};
		return arr[i];
	}
};
//	https://evileg.com/ru/post/289/
void err_out_of_range() {
	Arr arr;
	try {
		cout << "I can get: " << arr[20] << endl;
	}
	catch (std::out_of_range err) {
		cout << "No. U can't take more: "<< err.what() << endl;
	}
	catch (...) {
		cout << "or can't other reson\n";
	}
}
